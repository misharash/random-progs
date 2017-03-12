#!/usr/bin/env python3
def crange(k,rng,children,rangest):
    rangest[k][0]=max(rangest[k][0],rng)
    for chil in children[k]:
        crange(chil,rng+1,children,rangest)
n=int(input())
child=[]
nopar=[]
ranges=[]
for i in range(n):
    nopar.append(True)
    ranges.append([-1,i])
for i in range(n):
    child.append([])
    for chs in input().split(' ')[:-1]:
        ch=int(chs)-1
        child[i].append(ch)
        nopar[ch]=False
for i in range(n):
    if nopar[i]:
        crange(i,0,child,ranges)
ranges.sort()
s=""
for it in ranges:
    s+=str(it[1]+1)+" "
s=s[:-1]
print(s)