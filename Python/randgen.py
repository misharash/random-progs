#!/usr/bin/env python3
import random
import sys
helps="Randgen (Random Generator) 1.1 by MishaRash (Python 3 version), 2015-05-09.\nUsage:\n-b\t boolean value (True/False), default action\n-i <N>\t integer in range [0;N]\n-i <M> <N>\t integer in range [M;N]\n-f \t float in range [0;1]\n-f <N> \t float in range [0;N]\n-f <M> <N> \t float in range [M;N]\n-s <list of variants>\t select random variant from list.\n-h\t print help"
def boolrand():
    print(random.randint(0,1)==1)
def intrand():
    if len(sys.argv)>2:
        k=int(sys.argv[2])
        if len(sys.argv)>3:
            l=int(sys.argv[3])
            print(random.randint(k,l))
        else:
            print(random.randint(0,k))
    else:
        print("Too few arguments.\n"+helps)
def switchrand():
    if len(sys.argv)>2:
        print(random.choice(sys.argv[2:]))
    else:
        print("Too few arguments.\n"+helps)
def floatrand():
    if len(sys.argv)>2:
        k=float(sys.argv[2])
        if len(sys.argv)>3:
            l=float(sys.argv[3])
            print(random.uniform(k,l))
        else:
            print(random.uniform(0,k))
    else:
        print(random.random())
random.seed(version=2)
if len(sys.argv)==1:
    boolrand()
elif sys.argv[1]=="-b":
    boolrand()
elif sys.argv[1]=="-i":
    intrand()
elif sys.argv[1]=="-s":
    switchrand()
elif sys.argv[1]=="-f":
    floatrand()
elif sys.argv[1]=="-h":
    print(helps)
else:
    print("Unrecognized flag.\n"+helps)