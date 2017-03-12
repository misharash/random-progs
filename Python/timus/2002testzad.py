#!/usr/bin/env python3
n=int(input())
user,passwd,login=[],[],[]
for i in range(n):
    args=input().split(" ")
    if args[0]=="register":
        if args[1] in user:
            print("fail: user already exists")
        else:
            user.append(args[1])
            passwd.append(args[2])
            login.append(False)
            print("success: new user added")
    elif args[0]=="login":
        if args[1] in user:
            ind=user.index(args[1])
            if passwd[ind]==args[2]:
                if login[ind]:
                    print("fail: already logged in")
                else:
                    login[ind]=True
                    print("success: user logged in")
            else:
                print("fail: incorrect password")
        else:
            print("fail: no such user")
    else:
        if args[1] in user:
            ind=user.index(args[1])
            if login[ind]:
                login[ind]=False
                print("success: user logged out")
            else:
                print("fail: already logged out")
        else:
            print("fail: no such user")