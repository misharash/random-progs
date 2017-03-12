#!/usr/bin/env python3
ls=input().split(" ")
n=int(ls[0])
k=int(ls[1])
g=max((n+n%k)*(n//k),4*(n*n//4//k))
print(g)