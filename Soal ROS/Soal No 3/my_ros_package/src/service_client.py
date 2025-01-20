#!/usr/bin/env python
import rospy
from my_ros_package.srv import CustomService

def service_client():
    rospy.wait_for_service('custom_service')
    try:
        custom_service = rospy.ServiceProxy('custom_service', CustomService)
        response = custom_service(5)
        rospy.loginfo("Service response: %d", response)
    except rospy.ServiceException as e:
        rospy.logerr("Service call failed: %s", e)

if __name__ == '__main__':
    service_client()
