import math
import copy


class Point():
    def __init__(self, x, y):
        self.x = x
        self.y = y
 
def find_dist(p1, p2):
    return math.sqrt((p1.x - p2.x)**2 + (p1.y - p2.y)**2)
        
def brute_force(points, n):
    minimum = float('inf')
    for i in range(n):
        for j in range(i + 1, n):
            if find_dist(points[i], points[j]) < minimum:
                minimum = find_dist(points[i], points[j])
 
    return minimum

def closest_list(list, size, k):

    minimum = k
 
    for i in range(size):
        j = i + 1
        while j < size and (list[j].y -
                            list[i].y) < minimum:
            minimum = find_dist(list[i], list[j])
            j += 1
 
    return minimum

def find_closest(points, points_close, n):

    if n <= 3:
        return brute_force(points, n)

    mid = n // 2
    midpoint = points[mid]

    pointsleft = points[:mid]
    pointsright = points[mid:]

    kleft = find_closest(pointsleft, points_close, mid)
    kright = find_closest(pointsright, points_close, n - mid)

    k = min(kleft, kright)

    list_points = []
    list_close = []
    lr = pointsleft + pointsright
    for i in range(n):
        if abs(lr[i].x - midpoint.x) < k:
            list_points.append(lr[i])
        if abs(points_close[i].x - midpoint.x) < k:
            list_close.append(points_close[i])
 
    list_points.sort(key = lambda point: point.y)
    min1 = min(k, closest_list(list_points, len(list_points), k))
    min2 = min(k, closest_list(list_close, len(list_close), k))
     
    return min(min1,min2)

def closest(points, n):
    points.sort(key = lambda point: point.x)
    points_close = copy.deepcopy(points)
    points_close.sort(key = lambda point: point.y)   

    return find_closest(points, points_close, n)