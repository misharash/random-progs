#!/usr/bin/env python3
def c(n,k):
    r=1
    if 2*k<=n:
        for i in range(k):
            r*=(n-i)
            r=r//(i+1)
        return r
    for i in range(n-k):
        r*=(n-i)
        r=r//(i+1)
    return r
ls=input().split(" ")
b,r,y=int(ls[0]),int(ls[1]),int(ls[2])
bb,rr,yy=0,0,0
k=int(input())
s=""
for i in range(k):
    s=input()
    if s=="Blue":
        bb+=1
    elif s=="Red":
        rr+=1
    else:
        yy+=1
a=c(b,bb)*c(r,rr)*c(y,yy)
print(a)