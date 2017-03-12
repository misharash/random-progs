#!/usr/bin/env python3
def oint(str):
    ls=str.split(".")
    if len(ls)==1:
        return 10000*int(ls[0])
    return 10000*int(ls[0])+10**(4-len(ls[1]))*int(ls[1])
n=int(input())
s=oint(input())
l=oint(input())
k1=s//l
ll=s%l
k=n*k1
if ll!=0:
    k2=l//ll
    k+=n//k2
    if n%k2!=0:
        k+=1
print(k)