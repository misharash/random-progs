#include <stdio.h>
#include <string.h>
int imax(int a,int b) {
	if (a>b)
		return a;
	return b;
}
int main() {
	char table[4][3][5][11],ss[56],si[11],*ll,*oll;
	int i,j,k,p,h[5],n,t,sp[11],spc,l;
	h[4]=0;
	for (i=0;i<4;i++)
		h[i]=1;
	for (i=0;i<4;i++)
		for (j=0;j<3;j++)
			for (k=0;k<5;k++) {
				for (p=0;p<10;p++)
					table[i][j][k][p]=' ';
				table[i][j][k][10]='\0';
			}
	gets(ss);
	sscanf(ss,"%d",&n);
	for (t=0;t<n;t++) {
		gets(ss);
		gets(si);
		switch (si[1]) {
			case 'h': {
				j=1;
				break;
			}
			case 'a': {
				j=2;
				break;
			}
			default: {
				j=0;
				break;
			}
		}
		k=0;
		p=0;
		i=(int)si[strlen(si)-1]-49;
		oll=ss;
		while ((ll=strchr(oll,' '))!=NULL) {
			ll=&ll[1];
			l=(int)(ll-oll);
			if (p+l>11) {
				k++;
				p=0;
			}
			strncpy(&table[i][j][k][p],oll,l-1);
			p+=l;
			oll=ll;
		}
		l=strlen(oll);
		if (p+l>10) {
			k++;
			p=0;
		}
		strncpy(&table[i][j][k][p],oll,l);
		h[i]=imax(h[i],k+1);
	}
	for (i=0;i<5;i++) {
		printf("+----------+----------+----------+\n");
		for (k=0;k<h[i];k++) {
			for (j=0;j<3;j++)
				printf("|%s",&table[i][j][k]);
			printf("|\n");
		}
	}
	return 0;
}
