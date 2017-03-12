#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int n,c;
} numcount;
int icmp(const void* a,const void* b) {
	return *((int*)a)-*((int*)b);
}
int main() {
	int n,p,i,j,ca,k,ok=0,z=0;
	scanf("%d%d",&n,&p);
	int a[n];
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),icmp);
	numcount nc[n];
	nc[0].n=a[0];
	nc[0].c=1;
	j=0;
	for (i=1;i<n;i++)
		if (nc[j].n==a[i])
			nc[j].c++;
		else {
			j++;
			nc[j].n=a[i];
			nc[j].c=1;
		}
	j++;
	i=0;
	do {
		k=0;
		for (;((k+nc[i].c)*nc[i].n<=p)&&(i<j);i++)
			k+=nc[i].c;
		ok+=k;
		z++;
	} while ((i<j)&&(k>0));
	if (k==0)
		z--;
	printf("%d %d\n",ok,z);
	return 0;
}