#!/usr/bin/env python3
import math
ls=input().split(" ")
w=int(ls[0])
if len(ls)>1:
    d=int(ls[1])
else:
    d=0
ls=input().split(" ")
x0=int(ls[0])
if len(ls)>1:
    y0=int(ls[1])
else:
    y0=0
ls=input().split(" ")
x1=int(ls[0])
if len(ls)>1:
    y1=int(ls[1])
else:
    y1=0
s=input()
sx,sy=x1-x0,y1-y0
s0x,s0y,s1x,s1y=0,0,0,0
kx,ky=-1,-1
for ch in s:
    if ch=='L':
        kx+=1
        if s0x==0:
            s0x=x0
        s1x=x1
    elif ch=='R':
        kx+=1
        if s0x==0:
            s0x=w-x0
        s1x=w-x1
    elif ch=='F':
        ky+=1
        if s0y==0:
            s0y=y0
        s1y=y1
    elif ch=='B':
        ky+=1
        if s0y==0:
            s0y=d-y0
        s1y=d-y1
if kx>=0:
    sx=s0x+s1x+w*kx
if ky>=0:
    sy=s0y+s1y+d*ky
ss2=sx*sx+sy*sy
if ss2>0:
    ss=math.sqrt(ss2)
else:
    ss=0.0
print("{0:0.4f}".format(ss))