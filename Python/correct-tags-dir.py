#!/usr/bin/env python3
import sys
import os
import taglib
def dodir(path):
    print("Directory {0}".format(path))
    filelist=os.popen("ls -p '{0}'".format(path)).read().split('\n')
    for item in filelist:
        if len(item)>0:
            if item[-1]=='/':
                dodir(path+item)
            else:
                if ".mp3" in item:
                    dofile(path+item)
def dofile(filename):
    print("File {0}".format(filename))
    f=taglib.File(filename)
    for elem in f.tags:
        for i in range(len(f.tags[elem])):
            e=False
            for ch in f.tags[elem][i]:
                if 0xC0<=ord(ch) and ord(ch)<=0xFF:
                    e=True
            if e:
                try:
                    f.tags[elem][i]=f.tags[elem][i].encode('cp1252').decode('cp1251')
                except UnicodeError:
                    print("Error while converting '{0}'".format(f.tags[elem][i]))
    f.save()
dirname=sys.argv[1]
if dirname[-1]!='/':
    dirname+='/'
dodir(dirname)