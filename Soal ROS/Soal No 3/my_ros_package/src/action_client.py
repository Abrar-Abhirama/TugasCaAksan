#!/usr/bin/env python
import rospy
import actionlib
from my_ros_package.action import CustomAction

def action_client():
    client = actionlib.SimpleActionClient('custom_action', CustomAction)
    client.wait_for_server()

    goal = CustomAction.Goal()
    goal.goal = 10
    client.send_goal(goal)
    client.wait_for_result()

    result = client.get_result()
    rospy.loginfo("Action result: %d", result.result)

if __name__ == '__main__':
    action_client()
