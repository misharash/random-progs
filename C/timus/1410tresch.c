#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int wl[10002],wc=2,mlenr[10002];
bool mlene[10002];
int imax(int a,int b) {
	if (a>b)
		return a;
	return b;
}
int mlen(int wn) {
	if (mlene[wn])
		return mlenr[wn];
	int i,r=0;
	for (i=wn+2;i<wc;i++)
		r=imax(r,mlen(i));
	r+=wl[wn];
	mlene[wn]=true;
	mlenr[wn]=r;
	return r;
}
int main() {
	char s[524289];
	int i,p,l;
	wl[0]=0;
	wl[1]=0;
	while (gets(s)) {
		p=0;
		for (i=0;s[i]!='\0';i++)
			if (((s[i]<'a')||(s[i]>'z'))&&((s[i]<'A')||(s[i]>'Z'))) {
				l=i-p;
				//printf("%d\n",l);
				if (l>0) {
					wl[wc]=l;
					wc++;
				}
				p=i+1;
			}
		l=i-p;
		//printf("%d\n",l);
		if (l>0) {
			wl[wc]=l;
			wc++;
		}
	}
	for (i=0;i<1002;i++)
		mlene[i]=false;
	printf("%d\n",mlen(0));
	return 0;
}
