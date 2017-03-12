#!/usr/bin/env python3
import fractions
print('R1  R2')
print('  R3  ')
print('R4  R5')
R1=fractions.Fraction(input('R1='))
R2=fractions.Fraction(input('R2='))
R3=fractions.Fraction(input('R3='))
R4=fractions.Fraction(input('R4='))
R5=fractions.Fraction(input('R5='))
R = (R1*R2*R4 + R1*R2*R5 + R1*R3*R4 + R1*R3*R5 + R1*R4*R5 + R2*R3*R4 + R2*R3*R5 + R2*R4*R5)/(R1*R2 + R1*R3 + R1*R5 + R2*R3 + R2*R4 + R3*R5 + R3*R4 + R4*R5)
print('R={0}'.format(R))