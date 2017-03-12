#!/usr/bin/env python3
import math
st=input()
x,y=0.0,0.0
s=math.sqrt(2)/2
for ch in st:
    if ch=="0":
        break
    elif ch=="1":
        x-=s
        y-=s
    elif ch=="2":
        y-=1
    elif ch=="3":
        x+=s
        y-=s
    elif ch=="4":
        x-=1
    elif ch=="6":
        x+=1
    elif ch=="7":
        x-=s
        y+=s
    elif ch=="8":
        y+=1
    elif ch=="9":
        x+=s
        y+=s
print("{0:0.10f} {1:0.10f}".format(x,y))