#!/usr/bin/env python3
import sys
import taglib
filename=sys.argv[1]
wrongenc=sys.argv[2]
rightenc=sys.argv[3]
f=taglib.File(filename)
for elem in f.tags:
    for i in range(len(f.tags[elem])):
        f.tags[elem][i]=f.tags[elem][i].encode(wrongenc).decode(rightenc)
f.save()