#!/usr/bin/env python3
#Science part
from math import sqrt,pi
import scipy.integrate as scint
import scipy.optimize as scopt
c=3e5
H0=68
Om=0.315
Ol=0.685
def xs(z):
    return c/H0/sqrt(Om*(1+z)**3+Ol)
def x(z):
    return scint.quad(xs,0,z)[0]
def zx(xz):
    return scopt.brentq((lambda a: x(a)-xz),0,1e6)
k=1e6*150e6/(pi/180/3600)/(365.25*86400)
def ts(z):
    return 1/(H0*(1+z)*sqrt(Om*(1+z)**3+Ol))*k
def t(z):
    return scint.quad(ts,0,z)[0]
def zt(tz):
    return scopt.brentq((lambda a: t(a)-tz),0,1e6)
#Interface part
import argparse
parser=argparse.ArgumentParser(description='Cosmology Calculator')
parser.add_argument("-z",action='store_true',help='redshift')
parser.add_argument("-t",action='store_true',help='time from now (years)')
parser.add_argument("-x",action='store_true',help='distance (Mpc)')
parser.add_argument("value",type=float,help='assumed as redshift by default')
args=parser.parse_args()
if args.t:
    val=zt(args.value)
    print("z={0:0.6f}\nx={1:0.3f} Mpc".format(val,x(val)))
elif args.x:
    val=zx(args.value)
    print("z={0:0.6f}\nt={1:0.6e} years".format(val,t(val)))
else:
    print("t={0:0.6e} years\nx={1:0.3f} Mpc".format(t(args.value),x(args.value)))
