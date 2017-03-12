#!/usr/bin/env python3
fac=[1]
for i in range(1,20):
    fac.append(i*fac[i-1])
n=int(input())
outp=[]
while n>=0:
    k=fac[n]+1
    for i in range(2,n):
        k+=(fac[n]*(n-i+1))//fac[i]
    outp.append(k)
    n=int(input())
for c in outp:
    print(c)