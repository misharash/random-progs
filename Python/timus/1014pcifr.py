#!/usr/bin/env python3
n=int(input())
if n==0:
    print("10")
elif n==1:
    print("1")
else:
    s=""
    c=9
    while n>1 and c>1:
        if n%c==0:
            n=n//c
            s=str(c)+s
        else:
            c-=1
    if n==1:
        print(s)
    else:
        print("-1")