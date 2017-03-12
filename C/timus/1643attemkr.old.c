#include <stdio.h>
#include <stdbool.h>
typedef struct {
	int x,y;
} coords;
int imax(int a,int b) {
	if (a>b)
		return a;
	return b;
}
//void printarr(int* arr,int n,int m) {
//	printf("begin\n");
//	int i,j;
//	for (i=0;i<n;i++) {
//		for (j=0;j<m-1;j++)
//			printf("%d ",arr[i*m+j]);
//		printf("%d\n",arr[i*m+j]);
//	}
//	printf("end\n");
//}
int main() {
	int n,m,i,j,vf,vl,ii,jj,xx,yy,tpc[26],tpn,k=0;
	scanf("%d%d",&n,&m);
	coords ar[2],kr,vis[n*m],tp[26][2];
	char map[n][m+1];
	bool vmap[2][n][m];
	int time[2][n][m];
	for (i=0;i<26;i++)
		tpc[i]=0;
	for (i=0;i<n;i++) {
		scanf("%s",&map[i]);
		for (j=0;j<m;j++) {
			for (vf=0;vf<2;vf++) {
				vmap[vf][i][j]=false;
				time[vf][i][j]=-100;
			}
			switch (map[i][j]) {
				case '$': {
					ar[0].x=i;
					ar[0].y=j;
					time[0][i][j]=0;
					break;
				}
				case '!': {
					ar[1].x=i;
					ar[1].y=j;
					time[1][i][j]=0;
					break;
				}
				case '*': {
					kr.x=i;
					kr.y=j;
					break;
				}
				default: {
					if ((map[i][j]>='A')&&(map[i][j]<='Z')) {
						vl=(int)map[i][j]-65;
						tp[vl][tpc[vl]].x=i;
						tp[vl][tpc[vl]].y=j;
						tpc[vl]++;
					}
				}
			}
		}
	}
	for (i=0;i<2;i++) {
		vl=1;
		vis[0]=ar[i];
		//printf("%d %d\n",ar[i].x,ar[i].y);
		//printf("%d %d\n",vis[0].x,vis[0].y);
		vmap[i][vis[0].x][vis[0].y]=true;
		for (vf=0;(vf<vl)&&(time[i][kr.x][kr.y]<0);vf++) {
			for (ii=-1;ii<=1;ii++)
				for (jj=-1;jj<=1;jj++) {
					xx=vis[vf].x+ii;
					yy=vis[vf].y+jj;
					if (!(vmap[i][xx][yy])) {
						if ((map[xx][yy]=='.')||(map[xx][yy]=='*')||(map[xx][yy]=='!')||(map[xx][yy]=='$')) {
							vis[vl].x=xx;
							vis[vl].y=yy;
							vmap[i][xx][yy]=true;
							time[i][xx][yy]=time[i][vis[vf].x][vis[vf].y]+1;
							vl++;
						}
						else
							if ((map[xx][yy]>='A')&&(map[xx][yy]<='Z')) {
								vis[vl].x=xx;
								vis[vl].y=yy;
								vmap[i][xx][yy]=true;
								time[i][xx][yy]=time[i][vis[vf].x][vis[vf].y]+1;
								vl++;
								tpn=(int)map[xx][yy]-65;
								if ((tp[tpn][0].x==xx)&&(tp[tpn][0].y==yy))
									vis[vl]=tp[tpn][1];
								else
									vis[vl]=tp[tpn][0];
								vmap[i][vis[vl].x][vis[vl].y]=true;
								//printf("Teleport #%d\nfrom %d %d\nto %d %d\n",tpn,xx,yy,vis[vl].x,vis[vl].y);
								time[i][vis[vl].x][vis[vl].y]=time[i][vis[vf].x][vis[vf].y]+1;
								vl++;
							}
					}
				}
			//printarr(&time[i],n,m);
		}
		if (time[i][kr.x][kr.y]<0) {
			printf("Impossible\n");
			return 0;
		}
		k=imax(k,time[i][kr.x][kr.y]);
	}
	printf("%d\n",k);
	return 0;
}
