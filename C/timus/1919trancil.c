#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int w,h;
bool cilchk(int H,int L) {
	if (H<w)
		return false;
	if (h<=L)
		return true;
	long double sina=(long double)w/L,cosa=sqrtl(1-sina*sina),tga=sina/cosa,dh=tga*L,dl=(long double)L/cosa,hn=(long double)h*w/L+cosa*w;
	if (hn<=H)
		return true;
	return false;
}
int main() {
	int b;
	scanf("%d%d",&w,&h);
	if (w>h) {
		b=w;
		w=h;
		h=b;
	}
	int n,i,H,L;
	scanf("%d",&n);
	for (i=0;i<n;i++) {
		scanf("%d%d",&H,&L);
		if (cilchk(H,L))
			printf("Block the hole\n");
		else
			printf("Too small\n");
	}
	return 0;
}
