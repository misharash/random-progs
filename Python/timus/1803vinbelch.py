#!/usr/bin/env python3
ls=input().split(" ")
k=int(ls[0])
n=int(ls[1])
st=1
pst=0
va=[[1,1]]
for i in range(2,n+1):
    buf=st
    st+=pst
    pst=buf
    cst=st
    ban=0
    while cst>0:
        ban+=cst%k
        cst=cst//k
    #val=[]
    #val.append(ban)
    #val.append(i)
    #va.append(val)
    va.append([ban,i])
va.sort()
s=""
for it in va:
    s+=str(it[1])+" "
s=s[:-1]
print(s)