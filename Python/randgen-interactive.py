#!/usr/bin/env python3
import random
helps="Randgen (Random Generator) 1.1 by MishaRash (Python 3 interactive version), 2015-05-09.\nUsage:\n-b\t boolean value (True/False), default action\n-i <N>\t integer in range [0;N]\n-i <M> <N>\t integer in range [M;N]\n-f \t float in range [0;1]\n-f <N> \t float in range [0;N]\n-f <M> <N> \t float in range [M;N]\n-s <list of variants>\t select random variant from list.\n-h\t print help\n-e\t exit"
def arganalysis(string):
    if len(string)>0:
        if string[-1]=='\n':
            string=string[:-1]
        openquote1=False
        openquote2=False
        afterspace=True
        afterslash=False
        ls=[]
        ps=""
        for ch in string:
            if afterspace:
                afterspace=False
                if ch=='"':
                    openquote1=True
                elif ch=="'":
                    openquote2=True
                else:
                    ps+=ch
            elif openquote1:
                if afterslash:
                    afterslash=False
                    if ch=='"':
                        ps+=ch
                    elif ch=="\\":
                        ps+=ch
                    else:
                        ps+="\\"+ch
                elif ch=='"':
                    openquote1=False
                elif ch=="\\":
                    afterslash=True
                else:
                    ps+=ch
            elif openquote2:
                if afterslash:
                    afterslash=False
                    if ch=="'":
                        ps+=ch
                    elif ch=="\\":
                        ps+=ch
                    else:
                        ps+="\\"+ch
                elif ch=="'":
                    openquote2=False
                elif ch=="\\":
                    afterslash=True
                else:
                    ps+=ch
            elif ch==" ":
                ls.append(ps)
                ps=""
                afterspace=True
            else:
                ps+=ch
        ls.append(ps)
        return ls
    else:
        return([])
def boolrand(params):
    print(random.randint(0,1)==1)
def intrand(params):
    if len(params)>2:
        k=int(params[2])
        if len(params)>3:
            l=int(params[3])
            print(random.randint(k,l))
        else:
            print(random.randint(0,k))
    else:
        print("Too few arguments.\n"+helps)
def switchrand(params):
    if len(params)>2:
        print(random.choice(params[2:]))
    else:
        print("Too few arguments.\n"+helps)
def floatrand(params):
    if len(params)>2:
        k=float(params[2])
        if len(params)>3:
            l=float(params[3])
            print(random.uniform(k,l))
        else:
            print(random.uniform(0,k))
    else:
        print(random.random())
while True:
    random.seed(version=2)
    params=arganalysis(input())
    params.insert(0,"")
    if len(params)==1:
        boolrand(params)
    elif params[1]=="-b":
        boolrand(params)
    elif params[1]=="-i":
        intrand(params)
    elif params[1]=="-s":
        switchrand(params)
    elif params[1]=="-f":
        floatrand(params)
    elif params[1]=="-h":
        print(helps)
    elif params[1]=="-e":
        exit()
    else:
        print("Unrecognized flag.\n"+helps)