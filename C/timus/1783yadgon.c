#include <stdio.h>
int bdiv(int a,int b) {
	int r=a/b;
	if (a%b>0)
		r++;
	return r;
}
int imax(int a,int b) {
	if (a<b)
		return b;
	return a;
}
int main() {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	int nm=n+m-1,a[nm],c=0,p[n];
	for (i=0;i<nm;i++)
		scanf("%d",&a[i]);
	for (i=0;i<n;i++) {
		p[i]=a[i]-c;
		for (j=1;j<m;j++)
			p[i]=imax(p[i],bdiv(a[i+j]-c,j+1));
		c+=p[i];
	}
	for (i=0;i<n-1;i++)
		printf("%d ",p[i]);
	printf("%d\n",p[i]);
	return 0;
}
