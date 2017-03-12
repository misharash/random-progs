#!/usr/bin/env python3
n=int(input())
t=[0,2]
for i in range(1,n):
    t.append(t[i]+t[i-1])
print(t[n]) #идеально