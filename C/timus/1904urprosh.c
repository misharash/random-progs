#include <stdio.h>
#include <string.h>
typedef struct {
	int b,e;
} prom;
int pow2(int p) {
	int r=1,i;
	for (i=0;i<p;i++)
		r*=2;
	return r;
}
int prcmp(const void* a,const void* aa) {
	return (*((prom*)a)).b-(*((prom*)aa)).b;
}
//void printarr(prom* arr,int n) {
//	int i;
//	printf("Beginning of array\n");
//	printf("Size: %d\n",n);
//	for (i=0;i<n;i++)
//		printf("%d %d\n",arr[i].b,arr[i].e);
//	printf("End of array\n");
//}
int main() {
	int k,i,j;
	scanf("%d",&k);
	int a[k],kp=1,nkp,mkp=pow2(k);
	for (i=0;i<k;i++)
		scanf("%d",&a[i]);
	prom p[mkp],np[mkp];
	p[0].b=0;
	p[0].e=1;
	for (i=k-1;i>=0;i--) {
		//printarr(p,kp);
		nkp=0;
		for (j=0;j<kp;j++)
			if (p[j].b>0) {
				//printf("Then: %d %d %d\n",a[i],p[j].b,p[j].e);
				np[nkp].b=a[i]+p[j].b;
				np[nkp].e=a[i]+p[j].e;
				nkp++;
				np[nkp].b=a[i]-p[j].e;
				np[nkp].e=a[i]-p[j].b;
				nkp++;
			}
			else
				if (p[j].e>=0) {
					//printf("Else: %d %d\n",a[i],p[j].e);
					np[nkp].b=a[i]-p[j].e;
					np[nkp].e=a[i]+p[j].e;
					nkp++;
				}
		kp=nkp;
		memcpy(p,np,kp*sizeof(prom));
	}
	printf("%d\n",kp);
	qsort(p,kp,sizeof(prom),prcmp);
	for (i=0;i<kp;i++)
		printf("%d %d\n",p[i].b,p[i].e);
	return 0;
}