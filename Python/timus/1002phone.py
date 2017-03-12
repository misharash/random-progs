#!/usr/bin/env python3
while True:
    s=input()
    if s=="-1":
        break
    n=int(input())
    words=[]
    for i in range(n):
        word0=input()
        word="";
        for ch in word0:
            if ch=='i' or ch=='j':
                word+="1"
            elif ch=='a' or ch=='b' or ch=='c':
                word+="2"
            elif ch=='d' or ch=='e' or ch=='f':
                word+="3"
            elif ch=='g' or ch=='h':
                word+="4"
            elif ch=='k' or ch=='l':
                word+="5"
            elif ch=='m' or ch=='n':
                word+="6"
            elif ch=='p' or ch=='r' or ch=='s':
                word+="7"
            elif ch=='t' or ch=='u' or ch=='v':
                word+="8"
            elif ch=='w' or ch=='x' or ch=='y':
                word+="9"
            elif ch=='o' or ch=='q' or ch=='z':
                word+="0"
        if word in s:
            word.append(word)
    #доделать???