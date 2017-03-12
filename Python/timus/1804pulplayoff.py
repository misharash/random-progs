#!/usr/bin/env python3
t=int(input())
s=""
for i in range(t):
    ls=input().split(" ")
    x=int(ls[6])
    y=int(ls[10])
    ming=y-x
    maxg=30+y-x
    if ls[3]=="home":
        if ming<y:
            ming+=1
        if maxg>y:
            maxg-=1
    ming=max(ming,0)
    maxg=min(maxg,30)
    print(ming,maxg)