#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the activityNotifications function below.
def get_median(counting_sort, d, median_position):
    left,counter = 0,0
    while counter < median_position:
        counter += counting_sort[left]
        left += 1
    right = left
    left -= 1
    if counter > median_position or (d % 2) != 0:
        return left
    else :
        while counting_sort[right] == 0:
            right += 1
        return (left + right) / (2)

def activityNotifications(expenditure, d):
    counting_sort = [0]*201
    end = d
    current = 0
    for i in expenditure:
        counting_sort[i] += 1
    
    notifications = 0
    if d % 2 == 0:
        median_position = int(d/2)
    else :
        median_position =  int(d/2) + 1
    while end < len(expenditure):
        median = get_median(counting_sort, d,median_position)
        if (expenditure[end] >= median*2): 
            notifications += 1
        counting_sort[expenditure[current]] -= 1
        counting_sort[expenditure[end]] += 1
        current += 1
        end += 1
    return notifications

if __name__ == '__main__':

    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    expenditure = list(map(int, input().rstrip().split()))

    result = activityNotifications(expenditure, d)
    print(result)
