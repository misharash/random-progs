#!/usr/bin/env python3
ls=input().split(" ")
n=int(ls[0])
m=int(ls[1])
nd=[]
for i in range(n):
    nd.append([[],[]])
p=n+m-1
coeff=[]
for i in range(p):
    coeffl=[]
    for j in range(p+1):
        coeffl.append(0)
    coeff.append(coeffl)
for i in range(m):
    ls=input().split(" ")
    nfrom=int(ls[0])-1
    nto=int(ls[1])-1
    r=int(ls[2])
    nd[nfrom][0].append(i)
    nd[nto][1].append(i)
    coeff[i][i]=r;
    if nfrom!=0:
        coeff[i][m+nfrom-1]=-1
    if nto!=0:
        coeff[i][m+nto-1]=1
coeff[m][p]=-1
for i in range(n-1):
    for ndi in nd[i][0]:
        coeff[m+i][ndi]=-1;
    for ndi in nd[i][1]:
        coeff[m+i][ndi]=1;
for i in range(p-1):
    for j in range(i+1,p):
        for k in range(i+1,p+1):
            coeff[j][k]=coeff[j][i]*coeff[i][k]-coeff[i][i]*coeff[j][k]
        coeff[j][i]=0
ri=-coeff[p-1][p]/coeff[p-1][p-1]
print("{0:0.2f}".format(ri))