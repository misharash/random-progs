#include <stdio.h>
int iabs(int a) {
	if (a>=0)
		return a;
	return -a;
}
int main() {
	char i;
	int h[2][2],m[2][2],time[2];
	char s[15];
	for (i=0;i<2;i++) {
		scanf("%d.%d %d.%d",&h[i][0],&m[i][0],&h[i][1],&m[i][1]);
		time[i]=60*(h[i][1]-h[i][0])+m[i][1]-m[i][0];
	}
	int dh=(iabs(time[1]-time[0])+10)/120;
	if (dh>5) {
		time[0]+=1440;
		dh=(iabs(time[1]-time[0])+10)/120;
		if (dh>5) {
			time[0]-=2880;
			dh=(iabs(time[1]-time[0])+10)/120;
		}
	}
	printf("%d\n",dh);
	return 0;
}
