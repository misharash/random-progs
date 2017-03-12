#!/usr/bin/env python3
def oint(string):
    ls=string.split("e")
    m=150
    if len(ls)>1:
        m+=int(ls[1])
    ls=ls[0].split(".")
    r=int(ls[0])*10**m
    if len(ls)>1:
        if len(ls[1])==0:
            ls[1]="0"
        r+=int(ls[1])*10**(m-len(ls[1]))
    return r
def ostr(ch):
    if ch==0:
        return "0.0000000000000000000e0"
    sgn=""
    if ch<0:
        ch=-ch
        sgn="-"
    m=0
    p=10
    while p<=ch:
        m+=1
        p*=10
    return "{0}{1:d}.{2:019d}e{3:d}".format(sgn,ch//(10**m),(ch%(10**m))//(10**(m-19)),m-150)
n=int(input())
s=0
for i in range(n):
    s+=oint(input())
print(ostr(s))