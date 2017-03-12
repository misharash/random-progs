#!/usr/bin/env python3
from math import sin,cos,acos,pi
class trigvec:
    def __init__(self,lon,lat):
        self.x=cos(lon)*cos(lat)
        self.y=sin(lon)*cos(lat)
        self.z=sin(lat)
def avec(a,b):
    x=a.x*b.x+a.y*b.y+a.z*b.z
    if x>=1:
        return 0.0
    if x<=-1:
        return pi
    return acos(x)
R=6400
lat1,lon1=[float(x)*pi/180 for x in input().split()]
lat2,lon2=[float(x)*pi/180 for x in input().split()]
vec1,vec2=trigvec(lon1,lat1),trigvec(lon2,lat2)
dst=R*avec(vec1,vec2)
print(dst)
