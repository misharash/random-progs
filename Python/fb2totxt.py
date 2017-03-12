#!/usr/bin/env python3
import sys
import re
fb2=sys.argv[1]
txt=sys.argv[2]
enc=sys.argv[3]
p=re.compile(r'<.*?>')
with open(fb2,encoding=enc) as fb2f:
  with open(txt,"w",encoding=enc) as txtf:
    s=fb2f.readline()
    while len(s)>0:
      txtf.write(p.sub('',s))
      s=fb2f.readline()