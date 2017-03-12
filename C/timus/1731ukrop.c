#include <stdio.h>
int main() {
	int n,m,i;
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++)
		printf("%d ",83*i);
	printf("%d\n",83*i);
	for (i=1;i<m;i++)
		printf("%d ",89*i);
	printf("%d\n",89*i);
	return 0;
}

