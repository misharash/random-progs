#!/usr/bin/env python3
ls=input().split(" ")
n=int(ls[0])
s=int(ls[1])
k=100-int(ls[2])
t=0
while n>s:
    n*=k
    s*=100
    t+=1
print(t)