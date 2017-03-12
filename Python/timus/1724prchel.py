#!/usr/bin/env python3
def ischel(str,b,e,ans):
    #print("ischel({0},{1:d},{2:d},{3})".format(str,b,e,ans))
    l=len(str)
    if l==0:
        return True
    if l%2==1:
        return False
    if ans[b][e]!=-1:
        return ans[b][e]
    if ord(str[-1])-ord(str[0])==32:
        ans[b][e]=ischel(str[1:-1],b+1,e-1,ans)
        return ans[b][e]
    r=False
    for i in range(2,l,2):
        r=r or (ischel(str[:i],b,b+i-1,ans) and ischel(str[i:],b+i,e,ans))
        if r:
            ans[b][e]=r
            return r
    ans[b][e]=r
    return r
s=input()
l=len(s)
a=[]
for i in range(l):
    rw=[]
    for j in range(l):
        rw.append(-1)
    a.append(rw)
q=int(input())
ss=""
for i in range(q):
    ls=input().split(" ")
    l=int(ls[0])-1
    r=int(ls[1])-1
    if ischel(s[l:r+1],l,r,a):
        ss+="1"
    else:
        ss+="0"
print(ss)