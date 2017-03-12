#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int x,y;
	char d;
} conf;
typedef struct {
	int e;
	char d;
} prom;
int s[100000];
int confcmp(const void* ap,const void* bp) {
	conf a=*((conf*)ap),b=*((conf*)bp);
	int d=a.y-b.y;
	if (d)
		return d;
	d=a.x-b.x;
	if (d)
		return d;
	return a.d-b.d;
}
int promcmp(const void* ap,const void* bp) {
	prom a=*((prom*)ap),b=*((prom*)bp);
	int d=s[a.e]-s[b.e];
	if (d)
		return d;
	d=s[a.e+a.d-1]-s[b.e+b.d-1];
	if (d)
		return d;
	return a.d-b.d;
}
int prcocmp(prom a,conf b) {
	int d=s[a.e]-b.y;
	if (d)
		return d;
	d=s[a.e+a.d-1]-b.x;
	if (d)
		return d;
	return a.d-b.d;
}
int main() {
	int n,m,i,kk=0,mm=0,e,k=0,b;
	char j;
	scanf("%d",&n);
	prom d[50*n];
	for (i=0;i<n;i++)
		scanf("%d",&s[i]);
	scanf("%d",&m);
	conf c[m];
	for (i=0;i<m;i++)
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].d);
	for (i=0;i<n;i++)
		for (j=2;(j<=50)&&(i+j<=n);j++) {
			d[k].e=i;
			d[k].d=j;
			k++;
		}
	qsort(d,k,sizeof(prom),promcmp);
	qsort(c,m,sizeof(conf),confcmp);
	char str[n+1];
	for (i=0;i<n;i++)
		str[i]='0';
	str[n]='\0';
	//printf("%d %d %d\n",n,k,m);
	while ((kk<k)&&(mm<m)) {
		e=prcocmp(d[kk],c[mm]);
		//printf("%d %d\n%d %d %d %d %d\n%d %d %d\n%d\n",kk,mm,d[kk].x,d[kk].y,d[kk].d,d[kk].b,d[kk].e,c[mm].x,c[mm].y,c[mm].d,e);
		if (e>0)
			mm++;
		else {
			if (e==0) {
				b=d[kk].e+d[kk].d;
				for (i=d[kk].e;i<b;i++)
					str[i]='1';
			}
			kk++;
		}
	}
	printf("%s\n",str);
	return 0;
}
