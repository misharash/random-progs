#!/usr/bin/env python3
n=int(input())
a=[]
for i in range(n):
    a.append(input().split(' '))
print(a)
o=[[]]*(2*n-1)
for i in range(n):
    for j in range(n):
        o[i+j].insert(0,a[i][j]) #интересный баг
        print(o)
s=""
for oo in o:
    for e in oo:
        s+="{0} ".format(e)
s=s[:-1]
print(s)