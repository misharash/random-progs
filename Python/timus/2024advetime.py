#!/usr/bin/env python3
s=input()
k=int(input())
ls=[]
for i in range(26):
    ls.append(0)
for ch in s:
    ls[ord(ch)-97]+=1
ls.sort()
while ls[0]==0:
    ls.pop(0)
if k>=len(ls):
    print("{0:d} {1:d}".format(sum(ls),1))
else:
    ls.reverse()
    ln=ls.count(ls[k-1])
    p=k-ls.index(ls[k-1])
    v=1
    for i in range(ln-p+1,ln+1):
        v*=i
    for i in range(2,p+1):
        v=v//i
    print("{0:d} {1:d}".format(sum(ls[:k]),v))