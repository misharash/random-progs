#!/usr/bin/env python3
n=int(input())
bs=""
es=""
s=""
for i in range(1,n+1):
    bs+="sin({0:d}".format(i)
    es+=")"
    s="({0}{1}+{2:d})".format(s,bs+es,n+1-i)
    if i%2==0:
        bs+="+"
    else:
        bs+="-"
s=s[1:-1]
print(s)