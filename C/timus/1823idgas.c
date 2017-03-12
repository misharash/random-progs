#include <stdio.h>
#define R 8.314
int main() {
	int i,j,k=0;
	char s[30],c;
	int p[4]={0,0,0,0},r;//pV=RnT, pnVT
	double o;
	for (i=0;i<3;i++) {
		gets(s);
		sscanf(s,"%c = %d",&c,&r);
		if (c>'Z') {
			if (c=='p')
				j=0;
			else
				j=1;
		}
		else {
			if (c=='V')
				j=2;
			else
				j=3;
		}
		p[j]=r;
	}
	for (i=0;i<4;i++)
		if (!p[i]) {
			j=i;
			k++;
		}
	if (k>1) //а тут я положук
	return 0;
}