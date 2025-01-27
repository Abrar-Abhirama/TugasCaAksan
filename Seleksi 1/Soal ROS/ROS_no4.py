import cv2

img = cv2.imread('image.png', 0)
orb = cv2.ORB_create()
keypoints, descriptors = orb.detectAndCompute(img, None)

# Draw keypoints on the image
output_img = cv2.drawKeypoints(img, keypoints, None, color=(0, 255, 0))

cv2.imshow('ORB Features', output_img)
cv2.waitKey(0)
cv2.destroyAllWindows()
