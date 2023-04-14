
import rclpy
from rclpy.node import Node

from mazebot_msgs.msg import VictimDetected
from std_msgs.msg import String

from ctypes.wintypes import BOOL
import time
from token import EXACT_TOKEN_TYPES
from xmlrpc.client import boolean

from smbus2 import SMBus, i2c_msg
import RPi.GPIO as GPIO


TCS34725_I2C_ADDRESS = 0x29
MLX90614_I2C_ADDRESS = 0x5A
VL6180XV_I2C_ADDRESS = 0x29
VL53L4CD_I2C_ADDRESS = 0x52

# Color Sensor TCS34725 - Register and command constants
#------------------------------------------
_COMMAND_BIT = 0x80
TCS34725_REGISTER_ENABLE = 0x00
TCS34725_REGISTER_ATIME = 0x01
TCS34725_REGISTER_CONTROL = 0x0F
TCS34725_REGISTER_STATUS = 0x13
TCS34725_REGISTER_CDATA = 0x14
TCS34725_BIT_ENABLE_AEN = 0x02
TCS34725_BIT_ENABLE_PON = 0x01
TCS34725_BIT_STATUS_AVALID = 0x01
TCS34725_GAINS = (1, 4, 16, 60)

#Termparture Sensor MLX90614 - Register and command constants
MLX90614_REGISTER_TA    = 0x06
MLX90614_REGISTER_TOBJ1 = 0x07
MLX90614_REGISTER_TOBJ2 = 0x08
MLX90614_COMMAND_READ_RAM = 0x00
MLS90614_COMMAND_READ_EEPROM = 0x20

#Range Sensor VL53L4CD - Register
VL53L4CD_FIRMWARE_SYSTEM_STATUS = 0x00E5
VL53L4CD_SYSTEM_START = 0x0087
VL53L4CD_GPIO_HV_MUX_CTRL = 0x0030
VL53L4CD_GPIO_TIO_HV_STATUS = 0x0031
VL53L4CD_SYSTEM_INTERRUPT_CLEAR = 0x0086
VL53L4CD_VHV_CONFIG_TIMEOUT_MACROP_LOOP_BOUND = 0x0008
VL53L4CD_INTERMEASUREMENT_MS = 0x006C
VL53L4CD_RANGE_CONFIG_A = 0x005E
VL53L4CD_RANGE_CONFIG_B = 0x0061
VL53L4CD_RESULT_DISTANCE = 0x0096

#IO-Expander PCA9557
PCA9557_REGISTER_INPUTPORT = 0x00
PCA9557_REGISTER_OUTPUTPORT = 0x01
PCA9557_REGISTER_POLARITYINVERSION = 0x02
PCA9557_REGISTER_CONFIGURATION = 0x03

PCA9557_BIT_LED_COLORSENSOR = 0x01
PCA9557_BIT_SWITCH = 0x02
PCA9557_BIT_LED_BLUE = 0x04
PCA9557_BIT_LED_YELLOW = 0x08
PCA9557_BIT_LED_GREEN = 0x10
PCA9557_BIT_LED_RED = 0x20
PCA9557_BIT_I2C_ENABLE = 0x40
PCA9557_BIT_XSHUT_DISTANCESENSOR = 0x80

class SensorMazeBot:
        def __init__(self, pca9557_address = 0x00, smbus = None, period_ms = 100, red_max_value=None, green_max_value=None, blue_max_value=None, 
                     red_min_value=None, green_min_value=None, blue_min_value=None):
                self._pca9557_address = pca9557_address
                self._pca9557_output_state = 0x00

                self.bus = SMBus(1)

                #check for max values
                if red_max_value != None:
                    self.red_max_value = red_max_value
                else:
                    self.red_max_value = 0

                if green_max_value != None:
                    self.green_max_value = green_max_value
                else:
                    self.green_max_value = 0

                if blue_max_value != None:
                    self.blue_max_value = blue_max_value
                else:
                    self.blue_max_value = 0
                #check for min values
                if red_min_value != None:
                    self.red_min_value = red_min_value
                else:
                    self.red_min_value = 1

                if green_min_value != None:
                    self.green_min_value = green_min_value
                else:
                    self.green_min_value = 1

                if blue_min_value != None:
                    self.blue_min_value = blue_min_value
                else:
                    self.blue_min_value = 1
                   
                
                self._enable_pca9557()
                self._tcs34725_init(integration_time = period_ms, gain = 16)
                self._vl53l4cd_init(offset = 0, period = period_ms)
                self._mlx90614_init()
        
        def color_table_side(self, R,G,B): 
            if R > G and R > B and G < 0.7 * R and B < 0.7 * R : return "red"
            elif G > R and R < 0.5 * G : return "green"
            elif R > 0.5 and R < 0.8 and (G > 0.2 or B > 0.2) : return "yellow"
            else : return "not detected"

        def color_table_bottom(self, R,G,B): 
            
            if B > R and B > G and R < 0.5 * B and G < 0.5 * B : return "blue"
            elif R < 0.4 and G < 0.4 and B < 0.4 : return "black"
            else : return "not detected"
                
        def __del__(self):
                self.bus.close()

        def _enable_pca9557(self):
            if self._pca9557_address > 0:
                try:
                    self._pca9557_ok = False
                    self.bus.write_byte_data(self._pca9557_address, PCA9557_REGISTER_CONFIGURATION, PCA9557_BIT_SWITCH | PCA9557_BIT_XSHUT_DISTANCESENSOR)
                    # define initial states -> set all outputs to logic low
                    self._pca9557_output_state = 0x00
                    self.bus.write_byte_data(self._pca9557_address, PCA9557_REGISTER_OUTPUTPORT, self._pca9557_output_state)
                    print("pca9557 ok")
                    self._pca9557_ok = True
                except:
                    self._pca9557_ok = False
            return self._pca9557_ok

        def _tcs34725_init(self, integration_time = 100, gain = 1):
            print("tcs345725 init started")
            try:
                #print("started try catch")
                self._tcs34725_ok = False
                self.enable_smbus()
                time.sleep(0.03)
                #setup integration time
                self._tcs34725_integration_time = integration_time
                cycles = int(self._tcs34725_integration_time / 2.4)
                self._tcs34725_integration_time = cycles * 2.4
                self.bus.write_byte_data(TCS34725_I2C_ADDRESS, (TCS34725_REGISTER_ATIME | _COMMAND_BIT) & 0xFF, 256 - cycles)
                #print("survived Integration time")
                #poer on device and start measurements
                #setting the gain for the color sensor
                self.bus.write_byte_data(TCS34725_I2C_ADDRESS, (TCS34725_REGISTER_CONTROL | _COMMAND_BIT) & 0xFF, TCS34725_GAINS.index(gain))
                #print("survived gain")
                #activating the internal osciallators of to start the ADC transmissions
                reg_enable_value = self.bus.read_byte_data(TCS34725_I2C_ADDRESS, (TCS34725_REGISTER_ENABLE | _COMMAND_BIT) & 0xFF)
                #print("{:b}".format(reg_enable_value))
                self.bus.write_byte_data(TCS34725_I2C_ADDRESS, (TCS34725_REGISTER_ENABLE | _COMMAND_BIT) & 0xFF, reg_enable_value | TCS34725_BIT_ENABLE_PON)
                #print("survived Internal oscilator")
                time.sleep(0.03)
                #enable the ADC after the required sleep time
                self.bus.write_byte_data(TCS34725_I2C_ADDRESS, (TCS34725_REGISTER_ENABLE | _COMMAND_BIT) & 0xFF, reg_enable_value | TCS34725_BIT_ENABLE_PON | TCS34725_BIT_ENABLE_AEN)
                #print("survived the adc")
                self.disable_smbus()
                self._tcs34725_ok = True
            except:
                self._tcs34725_ok = False    #aufpassen
            return self._tcs34725_ok

        #the following functions are for interpreting the colors
        def _tcs34725_get_corrected_values(self):
            rawvalues = self.colors
            if(rawvalues[0] < 0):
                return [-1, -1, -1, -1]
            print(rawvalues)
            corValues = []
            corValues.append(rawvalues[1] / rawvalues[0]) #red value
            corValues.append(rawvalues[2] / rawvalues[0]) # green value
            corValues.append(rawvalues[3] / rawvalues[0])   #blue value
            return corValues
        
        def _tcs34725_get_normated_values(self):
            corValues = self._tcs34725_get_corrected_values()
            self._tcs34725_updateMINMAX(corValues)
            normValues = []
            #calculate the normated values
            #red
            normValues.append((corValues[0] - self.red_min_value)/(self.red_max_value-self.red_min_value))
            #green
            normValues.append((corValues[1] - self.green_min_value)/(self.green_max_value-self.green_min_value))
            #blue
            normValues.append((corValues[2] - self.blue_min_value)/(self.blue_max_value-self.blue_min_value))

            return normValues

        def _tcs34725_updateMINMAX(self, corValues):
            #check if a new maximum value is available (red)
            if corValues[0] > self.red_max_value:
                self.red_max_value = corValues[0]
            #check for green
            if corValues[1] > self.green_max_value:
                self.green_max_value = corValues[1]
            #chekc for blue
            if corValues[2] > self.blue_max_value:
                self.blue_max_value = corValues[2]
            #check if a new minimum value is available (red)
            if corValues[0] < self.red_min_value:
                self.red_min_value = corValues[0]
            #check for green
            if corValues[1] < self.green_min_value:
                self.green_min_value = corValues[1]
            #chekc for blue
            if corValues[2] < self.blue_min_value:
                self.blue_min_value = corValues[2]

        def _tcs34725_get_Color_Side(self):
            normValues = self._tcs34725_get_normated_values()
            r = normValues[0]
            g = normValues[1]
            b = normValues[2]
            #print ("{:.2f}".format(r),"{:.2f}".format(g),"{:.2f}".format(b))
            return self.color_table_side(r,g,b)

        def _tcs34725_get_Color_Bottom(self):
            normValues = self._tcs34725_get_normated_values()
            r = normValues[0]
            g = normValues[1]
            b = normValues[2]
            #print ("{:.2f}".format(r),"{:.2f}".format(g),"{:.2f}".format(b))
            return self.color_table_bottom(r,g,b)

        def _tcs34725_color_init(self):
            print("start moving over different colors")
            for _ in range(100):
                self._tcs34725_updateMINMAX(self._tcs34725_get_corrected_values())
                time.sleep(0.1)

        #method can be used to scan for I\B2C devices
        def scan(force=False):
            devices = []
            for addr in range(0x03, 0x77 + 1):
                read = SMBus.read_byte, (addr,), {'force':force}
                write = SMBus.write_byte, (addr, 0), {'force':force}

                for func, args, kwargs in (read, write):
                    try:
                        with SMBus(1) as bus:
                            data = func(bus, *args, **kwargs)
                            devices.append(addr)
                            break
                    except OSError as expt:
                        if expt.errno == 16:
                            # just busy, maybe permanent by a kernel driver or just temporary by some user code
                            pass
            for addr in devices:
                print('{:02X}'.format(addr))


        #distance Sensor VL53L4CD
        def _vl53l4cd_read_Byte(self, register) -> int:
            write = i2c_msg.write(VL53L4CD_I2C_ADDRESS, [(register >> 8) & 0xFF, register & 0xFF])
            read = i2c_msg.read(VL53L4CD_I2C_ADDRESS,1)
            self.bus.i2c_rdwr(write, read)
            b = list(read)

            return b[0]

        def _vl53l4cd_write_byte(self, register, byte) -> None:
            write = i2c_msg.write(VL53L4CD_I2C_ADDRESS, [(register >> 8) & 0xFF, register & 0xFF, byte])
            self.bus.i2c_rdwr(write)
        
        def _vl53l4cd_read_2Byte(self, register) -> int:
            write = i2c_msg.write(VL53L4CD_I2C_ADDRESS, [(register >> 8) & 0xFF, register & 0xFF])
            read = i2c_msg.read( register, 2)
            self.bus.i2c_rdwr(write, read)
            b = list(read)

            return (b[0] << 8) + b[1]

        def _vl53l4cd_init(self, offset: int = 0, period : int = 100):
            try:
                self._vl53l4cd_ok = False
                self.enable_smbus()
                
                time.sleep(0.1)

                if (self._vl53l4cd_read_byte(VL53L4CD_FIRMWARE_SYSTEM_STATUS) == 0x03):
                    self._vl53l4cd_load_settings(period)
                    
                
                self.range_offset = offset
                #start system
                #self._vl53l4cd_write_byte(VL53L4CD_SYSTEM_START, 0x40)
                i = 0
                while self._vl53l4cd_CheckForDataReady() == False:
                    time.sleep(0.001)
                    i = i+1
                    if i>1000:
                        break

                self._vl53l4cd_clear_interrupt()

                #stop ranging
                self._vl53l4cd_write_byte( VL53L4CD_SYSTEM_START, 0x00)
                self._vl53l4cd_write_byte( VL53L4CD_VHV_CONFIG_TIMEOUT_MACROP_LOOP_BOUND, 0x09)
                self._vl53l4cd_write_byte( 0x0B, 0x00)
                self._vl53l4cd_write_byte( 0x24, 0x05)
                self._vl53l4cd_write_byte( 0x25, 0x00)
                
                self._vl53l4cd_ok = self._vl53l4cd_setRangeTiming(50, 0)
                self.disable_smbus()
            except:
                self._vl53l4cd_ok = False
            return self._vl53l4cd_ok

        def _vl53l4cd_setRangeTiming(self, timing_budget_ms, inter_measurement_ms) -> bool:
            intermeasurement_factor = 1.055
            timing_budget_us = timing_budget_ms *1000
            osc_frequency = self._vl53l4cd_read_Byte(0x0006)
            macro_period_us = (2304 * (0x40000000 / osc_frequency)) >> 6;

            if timing_budget_ms < 10 or timing_budget_ms >200:
                return False
            elif inter_measurement_ms == 0: 
                self._vl53l4cd_write_byte( VL53L4CD_INTERMEASUREMENT_MS, 0x00)
                self._vl53l4cd_write_byte( VL53L4CD_INTERMEASUREMENT_MS + 1, 0x00)
                self._vl53l4cd_write_byte( VL53L4CD_INTERMEASUREMENT_MS + 2, 0x00)
                self._vl53l4cd_write_byte( VL53L4CD_INTERMEASUREMENT_MS + 3, 0x00)
                timing_budget_us = timing_budget_us - 2500

            elif inter_measurement_ms> timing_budget_ms:
                temp= self._vl53l4cd_read_2Byte(0x00DE)
                clock_pll = (temp[0] << 8) + temp[1]
                clock_pll = clock_pll & 0x3FF
                intermeasurement_factor = intermeasurement_factor * inter_measurement_ms * clock_pll
                self._vl53l4cd_write_byte(VL53L4CD_INTERMEASUREMENT_MS, (intermeasurement_factor >>24)&0xFF)   
                self._vl53l4cd_write_byte(VL53L4CD_INTERMEASUREMENT_MS + 1, (intermeasurement_factor>>16)&0xFF)
                self._vl53l4cd_write_byte(VL53L4CD_INTERMEASUREMENT_MS + 2, (intermeasurement_factor>>8)&0xFF)
                self._vl53l4cd_write_byte(VL53L4CD_INTERMEASUREMENT_MS + 3, (intermeasurement_factor>>0)&0xFF)

                timing_budget_us = timing_budget_us - 4300
                timing_budget_us = timing_budget_us / 2
            else:
                return False
            #set range config A
            msByte = 0
            timing_budget_us = timing_budget_us << 12
            tmp = macro_period_us * 16
            ls_Byte = ((timing_budget_us + ((tmp >> 6) >> 1)) / (tmp >> 6)) - 1

            while (ls_Byte & 0xFFFFFF00) > 0:
                ls_Byte = ls_Byte >> 1
                msByte = msByte + 1
            msByte = (msByte << 8) + (ls_Byte & 0xFF)
            self._vl53l4cd_write_byte(VL53L4CD_RANGE_CONFIG_A, (msByte >> 8)&0xFF)   
            self._vl53l4cd_write_byte(VL53L4CD_RANGE_CONFIG_A + 1, (msByte >> 0)&0xFF)
            
            #set range config B
            msByte = 0
            tmp = macro_period_us *12
            ls_Byte = ((timing_budget_us + ((tmp >> 6) >> 1)) / (tmp >> 6)) -1;
            while (ls_Byte & 0xFFFFFF00) > 0:
                ls_Byte = ls_Byte >> 1
                msByte = msByte + 1
            msByte = (msByte << 8) + (ls_Byte & 0xFF)
            self._vl53l4cd_write_byte(VL53L4CD_RANGE_CONFIG_B, (msByte >> 8)&0xFF)   
            self._vl53l4cd_write_byte(VL53L4CD_RANGE_CONFIG_B + 1, (msByte >> 0)&0xFF)

            return True
            
        def _vl53l4cd_clear_interrupt(self) -> None:
            self._vl53l4cd_write_byte(VL53L4CD_SYSTEM_INTERRUPT_CLEAR, 0x01)

        def _vl53l4cd_CheckForDataReady(self) -> bool:
            temp = self._vl53l4cd_read_Byte(VL53L4CD_GPIO_HV_MUX_CTRL)
            temp = temp & 0x10  #mask out bit 4
            temp = temp >> 4    #shift bit 4 to position 0

            if temp == 1:
                int_pol = 0
            else:
                int_pol = 1
            temp = self._vl53l4cd_read_Byte(VL53L4CD_GPIO_TIO_HV_STATUS)

            if (temp & 0x01) == int_pol:
                return True
            else:
                return False

        def _vl53l4cd_start_ranging(self) -> bool:
            b = self._vl53l4cd_read_2Byte( VL53L4CD_INTERMEASUREMENT_MS)
            temp = (b[0] << 8) + b[1]
            i=0
            if temp == 0:   #continous mode
                self._vl53l4cd_write_byte( VL53L4CD_SYSTEM_START, 0x21)
            else:           #autonomous mode
                self._vl53l4cd_write_byte( VL53L4CD_SYSTEM_START, 0x40)
            while True:
                if self._vl53l4cd_CheckForDataReady():
                    break
                elif i < 1000:
                    i = i+1
                else:
                    return False
                time.sleep(0.001)
            self._vl53l4cd_clear_interrupt()

            return True

        def _vl53l4cd_stop_ranging(self) -> None:
            self._vl53l4cd_write_byte( VL53L4CD_SYSTEM_START, 0x00)

        def _vl53l4cd_get_result(self) -> int:
            b = self._vl53l4cd_read_2Byte( VL53L4CD_RESULT_DISTANCE)

            return (b[0] << 8) & b[1]

        def _vl53l4cd_load_settings(self) -> None:
            #not modifiable
            self._vl53l4cd_write_byte(0x32, 0x00)
            self._vl53l4cd_write_byte(0x33, 0x02)
            self._vl53l4cd_write_byte(0x34, 0x08)
            self._vl53l4cd_write_byte(0x35, 0x00)
            self._vl53l4cd_write_byte(0x36, 0x08)
            self._vl53l4cd_write_byte(0x37, 0x10)
            self._vl53l4cd_write_byte(0x38, 0x01)
            self._vl53l4cd_write_byte(0x39, 0x01)
            self._vl53l4cd_write_byte(0x3A, 0x00)
            self._vl53l4cd_write_byte(0x3B, 0x00)
            self._vl53l4cd_write_byte(0x3C, 0x00)
            self._vl53l4cd_write_byte(0x3D, 0x00)
            self._vl53l4cd_write_byte(0x3E, 0xFF)
            self._vl53l4cd_write_byte(0x3F, 0x00)
            self._vl53l4cd_write_byte(0x40, 0x0F)
            self._vl53l4cd_write_byte(0x41, 0x00)
            self._vl53l4cd_write_byte(0x42, 0x00)
            self._vl53l4cd_write_byte(0x43, 0x00)
            self._vl53l4cd_write_byte(0x44, 0x00)
            self._vl53l4cd_write_byte(0x45, 0x00)
            self._vl53l4cd_write_byte(0x47, 0x0B)
            self._vl53l4cd_write_byte(0x48, 0x00)
            self._vl53l4cd_write_byte(0x49, 0x00)
            self._vl53l4cd_write_byte(0x4A, 0x02)
            self._vl53l4cd_write_byte(0x4B, 0x14)
            self._vl53l4cd_write_byte(0x4C, 0x21)
            self._vl53l4cd_write_byte(0x4D, 0x00)
            self._vl53l4cd_write_byte(0x4E, 0x00)
            self._vl53l4cd_write_byte(0x4F, 0x05)
            self._vl53l4cd_write_byte(0x50, 0x00)
            self._vl53l4cd_write_byte(0x51, 0x00)
            self._vl53l4cd_write_byte(0x52, 0x00)
            self._vl53l4cd_write_byte(0x53, 0x00)
            self._vl53l4cd_write_byte(0x54, 0xC8)
            self._vl53l4cd_write_byte(0x55, 0x00)
            self._vl53l4cd_write_byte(0x56, 0x00)
            self._vl53l4cd_write_byte(0x57, 0x38)
            self._vl53l4cd_write_byte(0x58, 0xFF)
            self._vl53l4cd_write_byte(0x59, 0x01)
            self._vl53l4cd_write_byte(0x5A, 0x00)
            self._vl53l4cd_write_byte(0x5B, 0x08)
            self._vl53l4cd_write_byte(0x5C, 0x00)
            self._vl53l4cd_write_byte(0x5D, 0x00)
            self._vl53l4cd_write_byte(0x5E, 0x01)
            self._vl53l4cd_write_byte(0x5F, 0xCC)
            self._vl53l4cd_write_byte(0x60, 0x07)
            self._vl53l4cd_write_byte(0x61, 0x01)
            self._vl53l4cd_write_byte(0x62, 0xF1)
            self._vl53l4cd_write_byte(0x63, 0x05)
            self._vl53l4cd_write_byte(0x68, 0x08)
            self._vl53l4cd_write_byte(0x69, 0x38)
            self._vl53l4cd_write_byte(0x6A, 0x00)
            self._vl53l4cd_write_byte(0x6B, 0x00)
            self._vl53l4cd_write_byte(0x70, 0x00)
            self._vl53l4cd_write_byte(0x71, 0x00)
            self._vl53l4cd_write_byte(0x76, 0x00)
            self._vl53l4cd_write_byte(0x77, 0x01)
            self._vl53l4cd_write_byte(0x78, 0x07)
            self._vl53l4cd_write_byte(0x79, 0x05)
            self._vl53l4cd_write_byte(0x7A, 0x06)
            self._vl53l4cd_write_byte(0x7B, 0x06)
            self._vl53l4cd_write_byte(0x7C, 0x00)
            self._vl53l4cd_write_byte(0x7D, 0x00)
            self._vl53l4cd_write_byte(0x7E, 0x02)
            self._vl53l4cd_write_byte(0x7F, 0xC7)
            self._vl53l4cd_write_byte(0x80, 0xFF)
            self._vl53l4cd_write_byte(0x81, 0x9B)
            self._vl53l4cd_write_byte(0x82, 0x00)
            self._vl53l4cd_write_byte(0x83, 0x00)
            self._vl53l4cd_write_byte(0x84, 0x00)
            self._vl53l4cd_write_byte(0x85, 0x01)
            #modifiable
            self._vl53l4cd_write_byte(0x2D, 0x00)   #Setting the I2C to 400KHz
            self._vl53l4cd_write_byte(0x2E, 0x01)   #setting pull-up to 3.3V I2C
            self._vl53l4cd_write_byte(0x2F, 0x01)   #setting pull-up to 3.3V GPIO
            self._vl53l4cd_write_byte(0x30, 0x11)   #active high interrupt
            self._vl53l4cd_write_byte(0x31, 0x02)
            self._vl53l4cd_write_byte(0x46, 0x20)
            self._vl53l4cd_write_byte(0x64, (0x64>>6)&0xFF)     #set Sigma threshhold
            self._vl53l4cd_write_byte(0x65, (0x64<<2)&0xFF)
            self._vl53l4cd_write_byte(0x66, (0x400>>8)&0xFF)    #set signal threshhold
            self._vl53l4cd_write_byte(0x67, (0x400>>0)&0xFF)
            self._vl53l4cd_write_byte(0x6C, (0x1F4>>24)&0xFF)   #set intermeasurement time to 500ms
            self._vl53l4cd_write_byte(0x6D, (0x1F4>>16)&0xFF)
            self._vl53l4cd_write_byte(0x6E, (0x1F4>>8)&0xFF)
            self._vl53l4cd_write_byte(0x6F, (0x1F4>>0)&0xFF)
            self._vl53l4cd_write_byte(0x72, 0x00)                 #set distance thresshold high, not needed
            self._vl53l4cd_write_byte(0x73, 0x00)
            self._vl53l4cd_write_byte(0x74, 0x00)                 #set distance thresshold low, not needed
            self._vl53l4cd_write_byte(0x75, 0x00)
            self._vl53l4cd_write_byte(0x86, 0x00)
            self._vl53l4cd_write_byte(0x87, 0x40)       #automatically starts ranging

            


        #Temperature Sensor MLX90414
        def _enable_mlx90614(self):
            if self._pca9557_address > 0:
                self._pca9557_output_state |= PCA9557_BIT_I2C_ENABLE
                self.bus.write_byte_data(self._pca9557_address, PCA9557_REGISTER_OUTPUTPORT, self._pca9557_output_state)
            else:
                self.enable_smbus()

        def _disable_mlx90614(self):
            if self._pca9557_address > 0:
                pass
                #self._pca9557_output_state &= ~(PCA9557_BIT_I2C_ENABLE | PCA9557_BIT_COLORSENSOR_ENABLE)
                #self.bus.write_byte_data(self._pca9557_address, PCA9557_REGISTER_OUTPUTPORT, self._pca9557_output_state)
            else:
                self.disable_smbus()

        def _mlx90614_init(self):
            try:
                self._mlx90614_ok = False
                self._mlx90614_read_temp(MLX90614_REGISTER_TOBJ1)
                self._mlx90614_ok = True
            except:
                self._mlx90614_ok = False
            return self._mlx90614_ok

        def _mlx90614_read_word(self, register):
            self._enable_mlx90614()
            data = self.bus.read_word_data(MLX90614_I2C_ADDRESS, register)
            #data = self.bus.read_block_data(MLX90614_I2C_ADDRESS, regsiter, 2)
            #data = data[1] << 8 | data [0]
            self._disable_mlx90614()
            return data

        def _mlx90614_read_temp(self, register):
            self._enable_mlx90614()
            temp = self._mlx90614_read_word(register)
            self._disable_mlx90614()
            temp *= 0.02
            temp -= 273.15
            return temp
        
        #activate sensors on PCB
        def enable_smbus(self):
            if self._pca9557_address > 0:
                print("adresse existiert")
                self._pca9557_output_state |= PCA9557_BIT_I2C_ENABLE
                self.bus.write_byte_data(self._pca9557_address, PCA9557_REGISTER_OUTPUTPORT, self._pca9557_output_state)
            else:
                GPIO.output(self._pin_enable_smbus, GPIO.HIGH)
        
        #deactivate sensors on PCB
        def disable_smbus(self):
            if self._pca9557_address > 0:
                self._pca9557_output_state &= ~PCA9557_BIT_I2C_ENABLE
                self.bus.write_byte_data(self._pca9557_address, PCA9557_REGISTER_OUTPUTPORT, self._pca9557_output_state)
            else:
                GPIO.output(self._pin_enable_smbus, GPIO.LOW)

        def enable_led(self, led_mask=PCA9557_BIT_LED_COLORSENSOR):
            if self._pca9557_address > 0:
                self._pca9557_output_state |= led_mask
                self.bus.write_byte_data(self._pca9557_address, PCA9557_REGISTER_OUTPUTPORT, self._pca9557_output_state)
            else:
                GPIO.output(self._pin_enable_led, GPIO.HIGH)

        def disable_led(self, led_mask=PCA9557_BIT_LED_COLORSENSOR):
            if self._pca9557_address > 0:
                if self._pca9557_ok:
                    self._pca9557_output_state &= ~led_mask
                    self.bus.write_byte_data(self._pca9557_address, PCA9557_REGISTER_OUTPUTPORT, self._pca9557_output_state)
            else:
                GPIO.output(self._pin_enable_led, GPIO.LOW)

        def enable_power(self):
            GPIO.output(self._pin_enable_power, GPIO.HIGH)

        def disable_power(self):
            GPIO.output(self._pin_enable_power, GPIO.LOW)

        @property
        def ambient_temperature(self):
            """Ambient Temperature in Celsius."""
            if self._mlx90614_ok:
                return self._mlx90614_read_temp(MLX90614_REGISTER_TA)
            else:
                return -1

        @property
        def object_temperature(self):
            """Object Temperature in Celsius."""
            if self._mlx90614_ok:
                return self._mlx90614_read_temp(MLX90614_REGISTER_TOBJ1)
            else:
                return -1

        @property
        def colors(self):
            if self._tcs34725_ok:
                self.enable_smbus()
                while not bool(self.bus.read_byte_data(TCS34725_I2C_ADDRESS, (TCS34725_REGISTER_STATUS | _COMMAND_BIT) & 0xFF) & TCS34725_BIT_STATUS_AVALID):
                        time.sleep((self._tcs34725_integration_time + 1.0) / 1000.0)

                block = self.bus.read_i2c_block_data(TCS34725_I2C_ADDRESS, (TCS34725_REGISTER_CDATA | _COMMAND_BIT) & 0xFF, 8)
                self.disable_smbus()
                c = (block[1] << 8) | block[0]
                r = (block[3] << 8) | block[2]
                g = (block[5] << 8) | block[4]
                b = (block[7] << 8) | block[6]

                return [c, r, g, b]
            else:
                return [-1, -1, -1, -1]

        @property 
        def range(self):
            if self._vl53l4cd_ok:
                self.disable_led(led_maks= PCA9557_BIT_LED_COLORSENSOR)
                time.sleep(0.005)
                while not self._vl53l4cd_CheckForDataReady():
                    pass

                #read range
                range_ = self._vl53l4cd_get_result()

                #clear interupt
                self._vl53l4cd_clear_interrupt()

                self.enable_led(led_maks= PCA9557_BIT_LED_COLORSENSOR)

                return range_
            return -1

        @property
        def switch(self):
            if self._pca9557_ok:
                if (self.bus.read_byte_data(self._pca9557_address, PCA9557_REGISTER_INPUTPORT) & PCA9557_BIT_SWITCH):
                    return 1
                else:
                    return 0
            else:
                return -1
        
        @property
        def result(self):
            res = self.colors
            res.append(self.object_temperature)
            res.append(self.range)
            res.append(self.switch)
            return res
        
        @property
        def result_header(self):
            header = ["clear", "red", "green", "blue"]
            return header
"""
        #main was only used for testing and logging the color values
if __name__ == '__main__':
        sensor = SensorMazeBot(pca9557_address=0x1B)
        __filename__ = "sensor" + datetime.today().strftime('%Y%m%d_%H%M%S') + ".csv"
        fw = open(__filename__, 'w')
        header = ";".join(sensor.result_header) 
        print(header)
        header += "\n"
        fw.write(header)
        fw.close()
        # Starting continuous mode
        print("Sensor_Robocup test v0.4")
        #sensor.enable_led(PCA9557_BIT_LED_COLORSENSOR)
        #sensor.enable_smbus()
        sensor.scan()
        #sensor._tcs34725_color_init()
        while 1: 
            fw = open(__filename__, 'a')     
            s = []
            
            res = sensor.result
            
            s.append("{:d}".format(res[0]))             #clear [digit]
            s.append("{:d}".format(res[1]))             #red [digit]
            s.append("{:d}".format(res[2]))             #green [digit]
            s.append("{:d}".format(res[3]))             #blue [digit]
            s = ";".join(s)
            print(s)
            s += "\n"
            fw.write(s)
            fw.close()

            time.sleep(0.1)
        #for _ in range(100):
                #res = sensor.colors
                #res.append(sensor.object_temperature)
                #res.append(sensor.range)
                #res = sensor.result
                #print("{:d}".format(res[0]), "{:d}".format(res[1]), "{:d}".format(res[2]), "{:d}".format(res[3]))#, "{:d}".format(res[4]), "{:d}".format(res[5]))
                #time.sleep(0.1)
        del sensor
        """

class RobuSensor(Node):

    def __init__(self):
        super().__init__('robu_sensor')
        #self.sensorLeft = SensorMazeBot(pca9557_address=0x1A, red_max_value=0.65, green_max_value=0.25, blue_max_value=0.25, 
        #             red_min_value=0.52, green_min_value=0.19, blue_min_value=0.21)
        self.sensorRight = SensorMazeBot(pca9557_address=0x1B, red_max_value=0.65, green_max_value=0.25, blue_max_value=0.25, 
                     red_min_value=0.52, green_min_value=0.19, blue_min_value=0.21)
        self.sensorBottom = SensorMazeBot(pca9557_address=0x19, red_max_value=None, green_max_value=None, blue_max_value=None, 
                     red_min_value=None, green_min_value=None, blue_min_value=None)

        self.pub_color = self.create_publisher(VictimDetected, 'colors_detected', 10)
        timer_period = 1.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = VictimDetected()

        #resultLeft = self.sensorLeft._tcs34725_get_Color_Side()
        resultRight = self.sensorRight._tcs34725_get_Color_Side()
        resultBottom = self.sensorBottom._tcs34725_get_Color_Side()
        # if(resultLeft == "red"):
        #     msg.victim_id = 'ROT'
        #     msg.victim_location = 1
        #     self.pub_color.publish(msg)
        # if(resultLeft == "green"):
        #     msg.victim_id = 'GRUN'
        #     self.pub_color.publish(msg)
        #     msg.victim_location = 1
        # if(resultLeft == "yellow"):
        #     msg.victim_id = 'GELB'
        #     msg.victim_location = 1
        #     self.pub_color.publish(msg)

        if(resultRight == "red"):
            msg.victim_id = 'ROT'
            msg.victim_location = 0
            self.pub_color.publish(msg)
        if(resultRight == "green"):
            msg.victim_id = 'GRUN'
            msg.victim_location = 0
            self.pub_color.publish(msg)
        if(resultRight == "yellow"):
            msg.victim_id = 'GELB'
            msg.victim_location = 0
            self.pub_color.publish(msg)

        if(resultBottom == "blue"):
            msg.victim_id = 'BLAU'
            self.pub_color.publish(msg)
            msg.victim_location = 2
        if(resultBottom == "black"):
            msg.victim_id = 'SCHWARZ'
            msg.victim_location = 2
            self.pub_color.publish(msg)

        
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    robu_sensor = RobuSensor()

    rclpy.spin(robu_sensor)

    robu_sensor.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
