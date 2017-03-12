#!/usr/bin/env python3
import math
s=input().split(" ")
for i in range(3):
    s[i]=int(s[i])
p=[[[0,s[0]],[s[0],0]],[[0,s[1]],[s[1],0]],[[0,s[2]],[s[2],0]]]
m=[1,1,1]
for i in range(3):
    while s[i]%2==0:
        s[i]=s[i]//2;
        m[i]*=2;
    for x in range(1,int(s[i]//1.4)+1):
        y=int(round(math.sqrt(s[i]**2-x**2)))
        if x**2+y**2==s[i]**2:
            p[i].append([m[i]*x,m[i]*y])
            p[i].append([m[i]*y,m[i]*x])
        else:
            y-=1
            if x**2+y**2==s[i]**2:
                p[i].append([m[i]*x,m[i]*y])
                p[i].append([m[i]*y,m[i]*x])
            else:
                y+=2
                if x**2+y**2==s[i]**2:
                    p[i].append([m[i]*x,m[i]*y])
                    p[i].append([m[i]*y,m[i]*x])
c=[[0,0],[0,0],[0,0]]
for p0 in p[0]:
    for p1 in p[1]:
        for p2 in p[2]:
            f=True
            if p0[0]+p1[0]==p2[0]:
                c[1][0]=p0[0]
                c[2][0]=p2[0]
            elif p0[0]-p1[0]==p2[0]:
                c[1][0]=p0[0]
                c[2][0]=p2[0]
            elif -p0[0]+p1[0]==p2[0]:
                c[1][0]=-p0[0]
                c[2][0]=p2[0]
            else:
                f=False
            if f:
                if p0[1]+p1[1]==p2[1]:
                    c[1][1]=p0[1]
                    c[2][1]=p2[1]
                elif p0[1]-p1[1]==p2[1]:
                    c[1][1]=p0[1]
                    c[2][1]=p2[1]
                elif -p0[1]+p1[1]==p2[1]:
                    c[1][1]=-p0[1]
                    c[2][1]=p2[1]
if (c[1][0]!=0 or c[2][0]!=0) and (c[1][1]!=0 or c[2][1]!=0):
    print(c[0][0],c[0][1])
    print(c[1][0],c[1][1])
    print(c[2][0],c[2][1])
else:
    print(-1)