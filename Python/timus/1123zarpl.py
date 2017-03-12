#!/usr/bin/env python3
z=input()
l=len(z)
ll=l//2
z1=z[:ll]
z2=z[-ll:]
zz=""
if l%2==1:
  zz=z[ll]
ls=list(z1)
ls.reverse()
z2z=str.join("",ls)
if z2>z2z and l>1:
    if len(zz)==0 or zz=="9":
        z1=str(int(z1)+1)
        ls=list(z1)
        ls.reverse()
        z2z=str.join("",ls)
        zz="0"*len(zz)
    else:
        zz=str(int(zz)+1)
zzz=z1+zz+z2z
print(zzz)