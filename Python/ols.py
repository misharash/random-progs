#!/usr/bin/env python3
import math
n=int(input("Введите количество точек: "))
print("Вводите точки в формате X Y.")
x,y=[],[]
for i in range(n):
    ls=input("{0}: ".format(i+1)).split(" ")
    x.append(float(ls[0]))
    y.append(float(ls[1]))
ask=input("Нужна корректировка точек (д/Н)? ")
while ("Д" in ask) or ("д" in ask):
    i=int(input("Введите номер пары: "))
    ls=input("{0}: ".format(i)).split(" ")
    x[i-1]=float(ls[0])
    y[i-1]=float(ls[1])
    ask=input("Нужна корректировка точек (д/Н)? ")
sx,sy,sx2,sy2,sxy=0.0,0.0,0.0,0.0,0.0
for i in range(n):
    sx+=x[i]
    sy+=y[i]
    sx2+=x[i]*x[i]
    sy2+=y[i]*y[i]
    sxy+=x[i]*y[i]
ax,ay,ax2,ay2,axy=sx/n,sy/n,sx2/n,sy2/n,sxy/n
a=(axy-ax*ay)/(ax2-ax*ax)
b=(ax2*ay-ax*axy)/(ax2-ax*ax)
s02=n/(n-2)*(ay2-ay*ay-(axy-ax*ay)*(axy-ax*ay)/(ax2-ax*ax))
sa2=s02/n/(ax2-ax*ax)
sb2=sa2*ax2
da=math.sqrt(sa2)
db=math.sqrt(sb2)
print("y=ax+b")
print("a=",a,"±",da,sep="")
print("b=",b,"±",db,sep="")