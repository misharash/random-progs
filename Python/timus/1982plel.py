#!/usr/bin/env python3
ls=input().split(' ')
n=int(ls[0])
k=int(ls[1])
vis=[False]*n
rebras=[]
for ss in input().split(' '):
    vis[int(ss)-1]=True
for i in range(n):
    ls=input().split(' ')
    for j in range(n):
        if j>i:
            rebras.append([int(ls[j]),i,j])
rebras.sort()
print(rebras)
s=0
for rebro in rebras:
    if not (vis[rebro[1]] and vis[rebro[2]]):
        vis[rebro[1]]=True
        vis[rebro[2]]=True
        s+=rebro[0]
print(s)