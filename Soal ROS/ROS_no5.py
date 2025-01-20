import cv2
import numpy as np
import matplotlib.pyplot as plt

def harris_corner_detection(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    gray = np.float32(gray)

    dst = cv2.cornerHarris(gray, 2, 3, 0.04)

    dst = cv2.dilate(dst, None)
    image[dst > 0.01 * dst.max()] = [0, 0, 255]
    
    return image, dst

def feature_matching(image1, image2):
    img1, corners1 = harris_corner_detection(image1.copy())
    img2, corners2 = harris_corner_detection(image2.copy())

    plt.subplot(1, 2, 1), plt.imshow(img1)
    plt.title('Pic 1'), plt.xticks([]), plt.yticks([])
    plt.subplot(1, 2, 2), plt.imshow(img2)
    plt.title('Pic 2'), plt.xticks([]), plt.yticks([])
    plt.show()

    points1 = np.argwhere(corners1 > 0.01 * corners1.max())
    points2 = np.argwhere(corners2 > 0.01 * corners2.max())
    
    matches = []
    for p1 in points1:
        min_distance = float('inf')
        best_match = None
        for p2 in points2:
            dist = np.linalg.norm(p1 - p2)
            if dist < min_distance:
                min_distance = dist
                best_match = p2
        if best_match is not None:
            matches.append((tuple(p1), tuple(best_match)))

    return matches

image1 = cv2.imread('image.png')
image2 = cv2.imread('image2.png')

matches = feature_matching(image1, image2)

print(f'Jumlah pasangan fitur yang ditemukan: {len(matches)}')

for match in matches:
    pt1 = match[0]
    pt2 = match[1]
    cv2.line(image1, tuple(pt1), tuple(pt2), (255, 0, 0), 2)

cv2.imshow('Pencocokan Fitur', image1)
cv2.waitKey(0)
cv2.destroyAllWindows()
