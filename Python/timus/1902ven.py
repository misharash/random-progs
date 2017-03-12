#!/usr/bin/env python3
ls=input().split(" ")
n=int(ls[0])
t=int(ls[1])
s=int(ls[2])
for sss in input().split(" "):
  ss=int(sss)
  print("{0:0.6f}".format((s+ss+t)/2))