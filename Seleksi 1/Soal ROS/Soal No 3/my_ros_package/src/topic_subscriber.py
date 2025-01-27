#!/usr/bin/env python
import rospy
from my_ros_package.msg import CustomMessage

def callback(msg):
    rospy.loginfo("Received message: %s with value %d", msg.data, msg.value)

def subscriber_node():
    rospy.init_node('topic_subscriber', anonymous=True)
    rospy.Subscriber('custom_topic', CustomMessage, callback)
    rospy.spin()

if __name__ == '__main__':
    subscriber_node()
