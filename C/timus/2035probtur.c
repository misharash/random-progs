#include <stdio.h>
int main() {
	int x,y,c;
	scanf("%d%d%d",&x,&y,&c);
	if (x+y<c)
		printf("Impossible\n");
	else {
		if (x>=c)
			printf("%d %d\n",c,0);
		else
			printf("%d %d\n",x,c-x);
	}
	return 0;
}
