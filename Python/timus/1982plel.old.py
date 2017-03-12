#!/usr/bin/env python3
ls=input().split(' ')
n=int(ls[0])
k=int(ls[1])
nvis=[True]*n
st=[1000000]*n
mst=[[1000000]*n]*n
els=[]
for ss in input().split(' '):
    nn=int(ss)
    els.append(nn)
for i in range(n):
    ls=input().split(' ')
    for j in range(n):
        mst[i][j]=int(ls[j])
for el in els:
    el-=1
    nvis[el]=False
    for i in range(n):
        st[i]=min(st[i],mst[el][i])
iopt=0
sopt=1000000
s=0
while iopt>=0:
    iopt=-100
    sopt=1000000
    for i in range(n):
        if nvis[i]:
            if st[i]<sopt:
                sopt=st[i]
                iopt=i
    if iopt>=0:
        s+=sopt
        nvis[iopt]=False
        for i in range(n):
            st[i]=min(st[i],mst[iopt][i])
print(s)