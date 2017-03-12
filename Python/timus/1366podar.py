#!/usr/bin/env python3
def kvar(p):
    if k[p]!=-1:
        #print(1000,p,k[p])
        return k[p]
    r=fac[p-1]
    for i in range(2,p):
        #print(2000,p,p-i,i,i-1)
        r+=fac[p]*kvar(p-i)//fac[p-i]//i//2
        #print(2000,p,i,r)
    #print(1000,p,r)
    #print(k[p])
    k[p]=r
    return r
n=int(input())
fac=[1]
for i in range(n):
    fac.append(fac[i]*(i+1))
k=[1,0]
for i in range(1,n):
    k.append(-1)
print(kvar(n))