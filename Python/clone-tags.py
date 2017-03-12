#!/usr/bin/env python3
import sys
import taglib
sourcefile=sys.argv[1]
destfile=sys.argv[2]
sf=taglib.File(sourcefile)
df=taglib.File(destfile)
df.tags=sf.tags
df.save()