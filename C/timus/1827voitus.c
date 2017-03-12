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
	int d=a.d-b.d;
	if (d)
		return d;
	d=a.x-b.x;
	if (d)
		return d;
	return a.y-b.y;
}
int promcmp(const void* ap,const void* bp) {
	prom a=*((prom*)ap),b=*((prom*)bp);
	int d=a.d-b.d;
	if (d)
		return d;
	d=s[a.e+a.d-1]-s[b.e+b.d-1];
	if (d)
		return d;
	return s[a.e]-s[b.e];
}
int prcocmp(prom a,conf b) {
	int d=a.d-b.d;
	if (d)
		return d;
	d=s[a.e+a.d-1]-b.x;
	if (d)
		return d;
	return s[a.e]-b.y;
}
int imax(int a,int b) {
	if (a>b)
		return a;
	return b;
}
int imin(int a,int b) {
	if (a<b)
		return a;
	return b;
}
int main() {
	int n,m,i,kk=0,mm=0,e,k=0,pk,b,nn,dm=0;
	char j,s[100000];
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&s[i]);
	scanf("%d",&m);
	conf c[m];
	for (i=0;i<m;i++) {
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].d);
		dm=imax(dm,c[i].d);
	}
	prom d[dm*n];
	for (j=2;j<=dm;j++) {
		pk=k;
		nn=n-j;
		for (i=0;i<=nn;i++) {
			d[k].e=i;
			d[k].d=j;
			k++;
		}
		qsort(&d[pk],k-pk,sizeof(prom),promcmp);
	}
	qsort(c,m,sizeof(conf),confcmp);
	char str[n+1];
	for (i=0;i<n;i++)
		str[i]='0';
	str[n]='\n';
	//printf("%d %d %d\n",n,k,m);
	while ((kk<k)&&(mm<m)) {
		e=prcocmp(d[kk],c[mm]);
		//printf("begin\n%d %d\n%d %d %d %d\n%d %d %d\n%d\nend\n",kk,mm,s[d[kk].e+d[kk].d-1],s[d[kk].e],d[kk].d,d[kk].e,c[mm].x,c[mm].y,c[mm].d,e);
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
	fwrite(str,sizeof(char),n+1,stdout);
	return 0;
}
