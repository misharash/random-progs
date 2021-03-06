#!/usr/bin/env python3
import fractions
n=int(input("Enter the number of nodes: "))
m=int(input("Enter the number of resistors: "))
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
    print("Resistor",i+1)
    nfrom=int(input("Beginning node: "))-1
    nto=int(input("End node: "))-1
    r=fractions.Fraction(input("Resistance: "))
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
ri=float(-coeff[p-1][p]/coeff[p-1][p-1])
rf=fractions.Fraction(-coeff[p-1][p]/coeff[p-1][p-1])
print("R={0}={1:f}".format(rf,ri));