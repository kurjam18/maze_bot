import sensor, image, time, math, pyb
from image import SEARCH_EX, SEARCH_DS
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class CameraPublisher(Node):

    def __init__(self):
        super().__init__('color_tracking_node')
        self.publisher_ = self.create_publisher(String, 'dedectet_letters', 10)

        self.templateU = image.Image("/u.pgm")
        self.templateS = image.Image("/s.pgm")
        self.templateH = image.Image("/h.pgm")
        self.publisher_.publish("programm gestartet")

    def run(self):
        a=0
        sensor.reset()
        while(True):

            sensor.set_pixformat(sensor.GRAYSCALE)
            sensor.set_framesize(sensor.QQVGA2)
            sensor.skip_frames(time = 1500)
            img = sensor.snapshot()

            h = img.find_template(self.templateH, 0.60, step=4, search=SEARCH_EX) 
            if h:
                img.draw_rectangle(h)
                msg = String()
                msg.data = "H"
                self.publisher_.publish(msg)

            u = img.find_template(self.templateU, 0.70, step=4, search=SEARCH_EX) 
            if u:
                img.draw_rectangle(u)
                msg = String()
                msg.data = "U"
                self.publisher_.publish(msg)

            s = img.find_template(self.templateS, 0.70, step=4, search=SEARCH_EX) 
            if s:
                img.draw_rectangle(s)
                msg = String()
                msg.data = "S"
                self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = CameraPublisher()
    node.run()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
