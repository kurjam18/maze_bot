#include <Dynamixel2Arduino.h>
#include <CheapStepper.h>
#include <math.h>

#define DXL_SERIAL Serial1
#define COMM_SERIAL Serial
const int DXL_DIR_PIN = 6; // DYNAMIXEL Shield DIR PIN

const uint8_t DXL_ID_MOTOR_LEFT = 2;
const uint8_t DXL_ID_MOTOR_RIGHT = 1;
const float DXL_PROTOCOL_VERSION = 2.0;
const int IN1 = 40;
const int IN2 = 41;
const int IN3 = 42;
const int IN4 = 43;
const int stepperInfo = 44;                // Pin for signaling the teensy if the stepper needs to move for the start
const float MAX_LINEAR_VELOCITY = 0.15;  // TO DO
const float MAX_ANGULAR_VELOCITY = 2; // TO DO
const float RADIUS = 0.025;
const float ACHSENABSTAND = 0.148;    // TO DO
const int STEP_SIZE_RESCUE_KITS = 30; // Angle in degrees between two rescue kits

String inputString = "";      // a String to hold incoming data
String subString = "";        // String zur extrahierung von Abschnitten des Strings
bool stringComplete = false;  // whether the string is complete
float currentRPM_left = 0;    // the current RPM on the left motor
float currentRPM_right = 0;   // The current RPM on the right motor
float currentLIN_vel = 0;     // the current linear velocity in [m/s]
float currentANG_vel = 0;     // te current angular velocity in [°/s]
bool moveClockwise = false;    // defines the direction of the Stepper Motor (true = clockwise rotation)
bool waiting = false;
bool turnRight = false;
bool movingLin=false;
bool movingAng=false;
bool isBusy=false;
int time_start = 0;
float distance_to_drive = 0;
float angle_to_turn = 0;
int rescueKitsRemaining = 12; // we always start with 12 kits

// declaring the object for the Dynamixel Communication Bus
Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

// declaring the stepper motor for the dropping mechanism
CheapStepper stepper(IN1, IN2, IN3, IN4);

// This namespace is required to use Control table item names
using namespace ControlTableItem;

void motor(float rpm_left, float rpm_right)
{
  dxl.setGoalVelocity(DXL_ID_MOTOR_LEFT, -rpm_left, UNIT_RPM);
  dxl.setGoalVelocity(DXL_ID_MOTOR_RIGHT, rpm_right, UNIT_RPM);
}

void updateRPM()
{
  float v_links = currentLIN_vel + ACHSENABSTAND / 2 * currentANG_vel;
  float v_rechts = currentLIN_vel - ACHSENABSTAND / 2 * currentANG_vel;

  currentRPM_left = v_links * 30 / (M_PI * RADIUS) * 0.96;
  currentRPM_right = v_rechts * 30 / (M_PI * RADIUS);
  motor(currentRPM_left, currentRPM_right);
}

String extractValue(String text, char end_char, int pos)
{
  String result = "";
  for (int i = pos; i < text.length(); i++)
  {
    if (text[i] == end_char)
    {
      break;
    }
    result += text[i];
  }
  return result;
}

void dropKit(int count)
{
  switch (count)
  {
  case 0:
  { // case 0 means that we have to do a half step
    stepper.newMoveDegrees(moveClockwise, STEP_SIZE_RESCUE_KITS / 2);
  }
  break;
  case 1:
  {
    rescueKitsRemaining -= 1;
    if(rescueKitsRemaining != 0)
      stepper.newMoveDegrees(moveClockwise, STEP_SIZE_RESCUE_KITS);
    else
      stepper.newMoveDegrees(moveClockwise, STEP_SIZE_RESCUE_KITS + STEP_SIZE_RESCUE_KITS/2);
    
  }
  break;
  case 2:
  {
    rescueKitsRemaining -= 2;
    if(rescueKitsRemaining != 0)
      stepper.newMoveDegrees(moveClockwise, STEP_SIZE_RESCUE_KITS*2);
    else
      stepper.newMoveDegrees(moveClockwise, STEP_SIZE_RESCUE_KITS*2 + STEP_SIZE_RESCUE_KITS/2);
    
  }
  break;
  case 3:
  {
    rescueKitsRemaining -= 3;
    if(rescueKitsRemaining != 0)
      stepper.newMoveDegrees(moveClockwise, STEP_SIZE_RESCUE_KITS*3);
    else
      stepper.newMoveDegrees(moveClockwise, STEP_SIZE_RESCUE_KITS*3 + STEP_SIZE_RESCUE_KITS/2);
   
  }
  break;
  }
}

void setup()
{
  pinMode(stepperInfo, INPUT);
  if (digitalRead(stepperInfo))
    dropKit(0);

  COMM_SERIAL.begin(9600);

  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID_MOTOR_RIGHT);
  dxl.ping(DXL_ID_MOTOR_LEFT);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID_MOTOR_LEFT);
  dxl.setOperatingMode(DXL_ID_MOTOR_LEFT, OP_VELOCITY);
  dxl.torqueOn(DXL_ID_MOTOR_LEFT);
  dxl.torqueOff(DXL_ID_MOTOR_RIGHT);
  dxl.setOperatingMode(DXL_ID_MOTOR_RIGHT, OP_VELOCITY);
  dxl.torqueOn(DXL_ID_MOTOR_RIGHT);

  // Inverse the direction of one of the motors so that the motors don't have oppisite signs
  dxl.torqueOff(DXL_ID_MOTOR_LEFT);
  dxl.writeControlTableItem(DRIVE_MODE, DXL_ID_MOTOR_LEFT, dxl.readControlTableItem(DRIVE_MODE, DXL_ID_MOTOR_LEFT) | 0x01);
  dxl.torqueOn(DXL_ID_MOTOR_LEFT);
  updateRPM();
}

void loop()
{
  stepper.run();

  int stepsLeft = stepper.getStepsLeft();

  // if the current move is done...
  
  if (stepsLeft == 0 && waiting)
  {
      if(turnRight)
        currentANG_vel = MAX_ANGULAR_VELOCITY;
      else
        currentANG_vel = -MAX_ANGULAR_VELOCITY;
      currentLIN_vel = 0;
      updateRPM();
      delay(1.57/MAX_ANGULAR_VELOCITY * 1000* 1.6);
      currentANG_vel = 0;
      currentLIN_vel = 0;
      updateRPM();
      waiting = false;
      isBusy = false;
  }

   if (movingLin)
  {
       if(millis()-time_start >= abs(distance_to_drive)/MAX_LINEAR_VELOCITY * 1000 * 1.30769)
      {
        currentANG_vel = 0;
        currentLIN_vel = 0;
        updateRPM();
        movingLin=false;
        isBusy = false;
      }
  }

   if (movingAng)
  {
      if(millis()-time_start >= abs(angle_to_turn)/MAX_ANGULAR_VELOCITY * 1000* 1.65)
      {
        currentANG_vel = 0;
        currentLIN_vel = 0;
        updateRPM();
        movingAng=false;
        isBusy = false;
      }
  }
  
  
  // wait for a new command
  if (stringComplete)
  {
    // extrahieren des command befehls
    subString = inputString.substring(0, 5);

    // Befehl zur steuerung der linearen velocity
    if (subString == "vlin:")
    {
      String value = extractValue(inputString, '\n', 5);
      float lin_vel_new = atof(value.c_str());
      if (lin_vel_new < -MAX_LINEAR_VELOCITY)
        lin_vel_new = -MAX_LINEAR_VELOCITY;

      else if (lin_vel_new > MAX_LINEAR_VELOCITY)
        lin_vel_new = MAX_LINEAR_VELOCITY;

      currentLIN_vel = lin_vel_new;
      COMM_SERIAL.println(currentLIN_vel);
      updateRPM();
    }

    // Befehl zur steuerung der lienaren velocity
    else if (subString == "vang:")
    {
      String value = extractValue(inputString, '\n', 5);
      float ang_vel_new = atof(value.c_str());
      if (ang_vel_new < -MAX_ANGULAR_VELOCITY)
        ang_vel_new = -MAX_ANGULAR_VELOCITY;

      else if (ang_vel_new > MAX_ANGULAR_VELOCITY)
        ang_vel_new = MAX_ANGULAR_VELOCITY;

      currentANG_vel = ang_vel_new;
      COMM_SERIAL.println(currentANG_vel);
      updateRPM();
    }

    // Befehl zum stoppen des Roboters
    else if (subString == "stop:")
    {
      currentANG_vel = 0;
      currentLIN_vel = 0;
      COMM_SERIAL.println("00.00");
      updateRPM();
    }

    // Befehl zum abwerfen von x Paketen
    else if (subString == "drop:")
    {
      String value = extractValue(inputString, '\n', 5);
      int resKits = atoi(value.c_str());

      if (resKits <= rescueKitsRemaining)
      {
        dropKit(resKits);
        COMM_SERIAL.println(rescueKitsRemaining);
      }

      else
      {
        COMM_SERIAL.println("-1");
      }
      }

    else if (subString == "right")
    {
      String value = extractValue(inputString, '\n', 5);
      int resKits = atoi(value.c_str());

      //dreh sequenz
      currentANG_vel = -MAX_ANGULAR_VELOCITY;
      currentLIN_vel = 0;
      updateRPM();
      delay(1.57/MAX_ANGULAR_VELOCITY * 1000* 180 / 110);
      currentANG_vel = 0;
      currentLIN_vel = 0;
      updateRPM();
      
      if (resKits <= rescueKitsRemaining)
      {
        dropKit(resKits);
        COMM_SERIAL.println(rescueKitsRemaining);
      }
      
      else
      {
        COMM_SERIAL.println("-1");
      }
      waiting = true;
      turnRight = true;
    }

    else if (subString == "left:")
    {
      String value = extractValue(inputString, '\n', 5);
      int resKits = atoi(value.c_str());

       //dreh sequenz
      currentANG_vel = MAX_ANGULAR_VELOCITY;
      currentLIN_vel = 0;
      updateRPM();
      delay(1.57/MAX_ANGULAR_VELOCITY * 1000* 1.6);
      currentANG_vel = 0;
      currentLIN_vel = 0;
      updateRPM();
      if (resKits <= rescueKitsRemaining)
      {
        dropKit(resKits);
        COMM_SERIAL.println(rescueKitsRemaining);
      }         
      else
      {
        COMM_SERIAL.println("-1");
      }
      waiting = true;
      turnRight = false;
    }


    else if (subString == "move:")
    {
      String value = extractValue(inputString, '\n', 5);
      distance_to_drive = atof(value.c_str());
      
      if (distance_to_drive >=0)
        {
          currentLIN_vel= MAX_LINEAR_VELOCITY;
          currentANG_vel = 0;
          updateRPM();
          time_start = millis();
        }

      if (distance_to_drive < 0)
        {
          currentLIN_vel= -MAX_LINEAR_VELOCITY;
          currentANG_vel = 0;
          updateRPM();
          time_start = millis();
        }
      movingLin = true;
      isBusy = true;
    }

    else if (subString == "turn:")
    {
      String value = extractValue(inputString, '\n', 5);
      angle_to_turn = atof(value.c_str());

      
      if (angle_to_turn < 0)
        {
          currentLIN_vel= 0;
          currentANG_vel = -MAX_ANGULAR_VELOCITY;
          updateRPM();
          time_start = millis();
        }

      if (angle_to_turn >= 0)
        {
          currentLIN_vel= 0;
          currentANG_vel = MAX_ANGULAR_VELOCITY;
          updateRPM();
          time_start = millis();
        }
        isBusy = true;
        movingAng=true;
    }

    // Befehl zum senden von gewünschten Daten
    else if (subString == "send:")
    {
      String command = extractValue(inputString, '\n', 5);
      if (command == "MotCurL")
        COMM_SERIAL.println(dxl.getPresentCurrent(DXL_ID_MOTOR_LEFT));
    }

    else if (subString == "busy:")
    {
      if (isBusy)
        COMM_SERIAL.println("true");
      else
        COMM_SERIAL.println("false");
    }

    // return error code
    else
    {
      COMM_SERIAL.println("Unknown Error");
    }
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent()
{
  while (COMM_SERIAL.available())
  {
    char inChar = (char)COMM_SERIAL.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    if (inChar == '\n')
    {
      stringComplete = true;
    }
  }
}
