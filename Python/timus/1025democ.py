#!/usr/bin/env python3
n=int(input())
k=[]
for ch in input().split(" "):
    k.append(int(ch))
k.sort()
o=0
for it in k[:n//2+1]:
    o+=it//2+1
print(o)