#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int i,s;
} day;
typedef struct {
	int x,y,d;
} conf;
int daycmp(const void* a,const void* b) {
	return ((*((day*)a)).s-(*((day*)b)).s);
}
int confcmp(const void* a,const void* b) {
	return ((*((conf*)a)).y-(*((conf*)b)).y);
}
int main() {
	int n,m,i,nn,mm,mmm,e;
	scanf("%d",&n);
	int s[n];
	day d[n];
	for (i=0;i<n;i++) {
		scanf("%d",&s[i]);
		d[i].i=i;
		d[i].s=s[i];
	}
	scanf("%d",&m);
	conf c[m];
	for (i=0;i<m;i++) {
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].d);
		c[i].d--;
	}
	qsort(d,n,sizeof(day),daycmp);
	qsort(c,m,sizeof(conf),confcmp);
	char str[n+1];
	for (i=0;i<n;i++)
		str[i]='0';
	str[n]='\0';
	nn=0;
	mm=0;
	while ((nn<n)&&(mm<m)) {
		//printf("%d %d\n",nn,mm);
		if (c[mm].y<d[nn].s)
			mm++;
		else
			if (c[mm].y>d[nn].s)
				nn++;
			else {
				for (mmm=mm;(mmm<m)&&(c[mm].y==c[mmm].y);mmm++)
					if ((c[mmm].y==d[nn].s)&&(((e=d[nn].i+c[mmm].d)>=n)||(s[e]==c[mmm].x)))
						for (i=d[nn].i;(i<=e)&&(i<n);i++)
							str[i]='1';
				//printf("%d %d %d %d %d\n",c[mm].y,d[nn].s,e,s[e],c[mm].x);
				nn++;
			}
	}
	printf("%s\n",str);
	return 0;
}
