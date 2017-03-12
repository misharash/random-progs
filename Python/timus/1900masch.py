#!/usr/bin/env python3
ls=input().split(' ')
n=int(ls[0])
k=int(ls[1])
lp=[]
for i in range(n-1):
    lp.append([0,i+1])
cp=0
for i in range(n-1):
    ls=input().split(' ')
    for j in range(len(ls)):
        cp=int(ls[j])
        for kk in range(i,i+j+1):
            lp[kk][0]+=cp #логическая ошибка, одного пассажира могут осчастливить многократно
lp.sort()
lp.reverse()
pp=[]
for p in lp[:k]:
    pp.append(p[1])
pp.sort()
s=""
for p in pp:
    s+=str(p)+" "
s=s[:-1]
print(s)