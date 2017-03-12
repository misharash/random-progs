#!/usr/bin/env python3
def kb(n,s):
    if e[n][s]:
        return k[n][s]
    r=0
    for i in range(min(10,s+1)):
        r+=kb(n-1,s-i)
    e[n][s]=True
    k[n][s]=r
    return r
ls=input().split(" ")
n=int(ls[0])
s=int(ls[1])
if s%2==1:
    print(0)
else:
    s=s//2
    k,e,kl,el=[],[],[],[]
    for i in range(501):
        el.append(True)
        kl.append(0)
    k.append(kl)
    e.append(el)
    k[0][0]=1
    for i in range(1,51):
        kl,el=[],[]
        for j in range(501):
            kl.append(0)
            el.append(False)
        k.append(kl)
        e.append(el)
    print(kb(n,s)**2)