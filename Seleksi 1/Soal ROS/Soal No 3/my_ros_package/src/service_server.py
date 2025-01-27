#!/usr/bin/env python
import rospy
from my_ros_package.srv import CustomService

def handle_service(req):
    result = req.input * 2
    rospy.loginfo("Service request: %d, Response: %d", req.input, result)
    return result

def service_server():
    rospy.init_node('service_server')
    s = rospy.Service('custom_service', CustomService, handle_service)
    rospy.loginfo("Service ready")
    rospy.spin()

if __name__ == '__main__':
    service_server()
