#!/usr/bin/env python3
import sys,math
nums = []
for line in sys.stdin:
  for word in line.split():
    nums.append(float(word))
nums.reverse()
for num in nums:
  print("{0:0.4f}".format(math.sqrt(num)))