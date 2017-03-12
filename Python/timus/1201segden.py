#!/usr/bin/env python3
def daynum(d,m,y):
    r=d;
    for i in range(1600,y):
        r+=365
        if i%4==0:
            if i%100!=0:
                r+=1
            elif i%400==0:
                r+=1
    for i in range(1,m):
        if i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12:
            r+=31
        elif i==4 or i==6 or i==9 or i==11:
            r+=30
        elif i==2:
            r+=28
            if y%4==0:
                if y%100!=0:
                    r+=1
                elif y%400==0:
                    r+=1
    return r
def mdays(m,y):
    r=0
    if m==1 or m==3 or m==5 or m==7 or m==8 or m==10 or m==12:
        r=31
    elif m==4 or m==6 or m==9 or m==11:
        r=30
    elif m==2:
        r=28
        if y%4==0:
            if y%100!=0:
                r+=1
            elif y%400==0:
                r+=1
    return r
def sstr(n):
    if n<1 or n>dm:
        return spr*2
    if n<10:
        return spr+str(n)
    return str(n)
ls=[int(it) for it in input().split(" ")]
d,m,y=ls[0],ls[1],ls[2]
s=(daynum(1,m,y)-3)%7-1
dm=mdays(m,y)
w=-((-s-dm-1)//7)
c=["mon","tue","wed","thu","fri","sat","sun"]
leng=1
cd=0
spr=" "
for i in range(7):
    c[i]+=spr
for i in range(w):
    #if 7*(i+1)-1-s>=10:
        #leng=2
    if i>0:
        leng=2
    for j in range(7):
        cd=7*i+j-s
        if cd==d:
            c[j]+=spr*(leng-1)+"["+sstr(cd)+"]"
        else:
            c[j]+=spr*leng+sstr(cd)+spr
for i in range(7):
    if c[i][-1]==spr:
        c[i]=c[i][:-1]
for strg in c:
    print(strg)#+"e"