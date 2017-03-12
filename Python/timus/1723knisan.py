#!/usr/bin/env python3
s=input()
l=len(s)
sl=[]
for i in range(l):
    for j in range(i+1,l+1):
        sl.append(s[i:j])
kmax=0
smax=""
lmax=0
for it in sl:
    k=0
    l=len(it)
    for it2 in sl:
        if it==it2:
            k+=1
    if (k>kmax) or (k==kmax and l>lmax):
        kmax=k
        smax=it
        lmax=l
print(smax)