#include <stdio.h>
#include <string.h>
int main() {
	int n,i,j,k[3]={0,0,0},imax=0;
	scanf("%d\n",&n);
	char s[20],ss[3][20]={"Emperor Penguin","Little Penguin","Macaroni Penguin"};
	for (i=0;i<n;i++) {
		gets(s);
		for (j=0;j<3;j++)
			if (!strcmp(s,&ss[j]))
				k[j]++;
	}
	for (i=1;i<3;i++)
		if (k[i]>k[imax])
			imax=i;
	printf("%s\n",&ss[imax]);
	return 0;
}
