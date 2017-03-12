#!/usr/bin/env python3
def fib(k):
    if k>=0:
        return f[k]
    return f[-k]*(2*(k%2)-1)
ls=input().split(" ")
i=int(ls[0])
fi=int(ls[1])
j=int(ls[2])
fj=int(ls[3])
n=int(ls[4])
m=max(abs(i),abs(j),abs(n))
f=[0,1]
for t in range(m+10):
    f.append(f[t]+f[t+1])
f0=(fi*fib(j)-fj*fib(i))//(fib(i-1)*fib(j)-fib(j-1)*fib(i))
f1=-(fi*fib(j-1)-fj*fib(i-1))//(fib(i-1)*fib(j)-fib(j-1)*fib(i))
if i==0:
    f0=fi
elif j==0:
    f0=fj
if i==1:
    f1=fi
elif j==1:
    f1=fj
fn=f0*fib(n-1)+f1*fib(n)
print(fn)
