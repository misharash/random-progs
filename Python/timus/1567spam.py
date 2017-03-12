#!/usr/bin/env python3
s=input()
p=len(s)
for ch in s:
    if ch in ['c','f','i','l','o','r','u','x','!']:
        p+=2
    elif ch in ['b','e','h','k','n','q','t','w','z',',']:
        p+=1
print(p)