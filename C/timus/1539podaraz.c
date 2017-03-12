#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main() {
	int d,n,i,j,p=1,p2,m,c[2],t[2];
	bool e;
	scanf("%d%d",&d,&n);
	int s[n];
	for (i=0;i<d;i++)
		p*=10;
	p2=2*p;
	for (i=0;i<n;i++)
		scanf("%*d.%d",&s[i]);
	for (i=1;i<p;i++) {
		e=true;
		for (j=0;j<n;j++)
			if (s[j]) {
				m=(long long)s[j]*i/p;
				c[0]=(long long)m*p2/i;
				c[1]=(long long)(m+1)*p2/i;
				t[1]=2*s[j];
				t[0]=t[1]-1;
				//printf("%d %d %d %d %d %d %d %d\n",i,j,s[j],m,c[0],c[1],t[0],t[1]);
				if ((c[0]!=t[0])&&(c[1]!=t[1])&&(c[1]!=t[0])&&(c[0]!=t[1])) {
					e=false;
					break;
				}
			}
		if (e)
			break;
	}
	printf("%d\n",i);
	return 0;
}