#!/usr/bin/env python3
n=int(input())
r=0
p=n
for i in range(n-1,0,-1):
    p*=i
    r+=p
print(r)