#!/usr/bin/env python3
n=int(input())
ks=[]
for k in input().split(" "):
  ks.append(int(k))
maxx=0
maxi=1
for i in range(1,n-1):
  curr=ks[i]+ks[i+1]+ks[i-1]
  if curr>maxx:
    maxx=curr
    maxi=i
print(maxx,maxi+1,sep=" ")