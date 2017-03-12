#!/usr/bin/env python3
n=int(input())
ss=[]
b=0
for i in range(n):
    s=input()
    if s in ss:
        b+=1
    else:
        ss.append(s)
print(b)