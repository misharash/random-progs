#!/usr/bin/env python3
ls=input().split(" ")
n=int(ls[0])
k=len(ls[1])
r=1
while n>0:
    r*=n
    n-=k
print(r)