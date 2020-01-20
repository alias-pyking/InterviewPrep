#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the whatFlavors function below.
def whatFlavors(cost, money):
    hashmap = {i:[[],0] for i in cost}
    n = len(cost)
    for i in range(n):
        hashmap[cost[i]][0].append(i)
        hashmap[cost[i]][1] += 1
    result = list()
    for i in hashmap.keys():
        if hashmap[i][1] > 0:
            t = money
            if t - i > 0:
                hashmap[i][1] -= 1
                t = t - i
                if t in hashmap and hashmap[t][1] > 0:
                    result.append(hashmap[i][0].pop())
                    result.append(hashmap[t][0].pop())
                else:
                    hashmap[i][1] += 1
    
    result = sorted(result)
    print(result)

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        money = int(input())

        n = int(input())

        cost = list(map(int, input().rstrip().split()))

        whatFlavors(cost, money)
