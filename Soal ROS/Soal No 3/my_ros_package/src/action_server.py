#!/usr/bin/env python
import rospy
import actionlib
from my_ros_package.action import CustomAction
from actionlib_msgs.msg import GoalStatus

def execute_action(goal):
    feedback = CustomAction.Feedback()
    result = CustomAction.Result()
    for i in range(10):
        feedback.feedback = i
        rospy.loginfo("Feedback: %d", i)
        server.publish_feedback(feedback)
        rospy.sleep(1)

    result.result = goal.goal * 2
    rospy.loginfo("Result: %d", result.result)
    server.set_succeeded(result)

def action_server():
    rospy.init_node('action_server')
    global server
    server = actionlib.SimpleActionServer('custom_action', CustomAction, execute_action, False)
    server.start()
    rospy.spin()

if __name__ == '__main__':
    action_server()
