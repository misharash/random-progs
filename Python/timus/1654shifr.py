#!/usr/bin/env python3
def dech(str):
    bch='\n'
    ss=""
    for ch in s:
        if ch==bch:
            bch='\n'
        else:
            if bch!='\n':
                ss+=bch
            bch=ch
    if bch!='\n':
        ss+=bch
    return ss
s=input()
bs=""
while s!=bs:
    bs=s;
    s=dech(bs)
print(s)