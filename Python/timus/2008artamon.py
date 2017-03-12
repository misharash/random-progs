#!/usr/bin/env python3
def pryg(c1,c2):
  x=c2[0]-c1[0]
  y=c2[1]-c1[1]
  D=100*v**4-20*g10*y*v**2-g10**2*x**2
  return D>0
g10=98
v=int(input())
c=[]
for i in range(3):
  c.append([int(it) for it in input().split(" ")])
if pryg(c[1],c[2]) and pryg(c[2],c[1]) and (pryg(c[1],c[0]) or pryg(c[2],c[0])):
  print("Yes")
else:
  print("No")
