#!/usr/bin/env python
import rospy
from my_ros_package.msg import CustomMessage

def publisher_node():
    rospy.init_node('topic_publisher', anonymous=True)
    pub = rospy.Publisher('custom_topic', CustomMessage, queue_size=10)
    rate = rospy.Rate(10)  # 10 Hz
    while not rospy.is_shutdown():
        msg = CustomMessage()
        msg.data = "Hello, ROS!"
        msg.value = 42
        rospy.loginfo("Publishing: %s", msg.data)
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        publisher_node()
    except rospy.ROSInterruptException:
        pass
