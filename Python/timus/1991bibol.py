#!/usr/bin/env python3
ls=input().split(' ')
n=int(ls[0])
k=int(ls[1])
nb,vd=0,0
for bs in input().split(' '):
    kb=int(bs)
    nb+=max(0,kb-k)
    vd+=max(0,k-kb)
print(nb,vd,sep=' ')