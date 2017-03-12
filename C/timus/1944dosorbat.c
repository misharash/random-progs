#include <stdio.h>
#include <stdlib.h>
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
    int n,i,j;
    scanf("%d",&n);
    int x[n],y[n],xmin=0,xmax=0,ymin=0,ymax=0;
    for (i=0;i<n;i++) {
        scanf("%d%d",&x[i],&y[i]);
        xmin=imin(xmin,x[i]);
        ymin=imin(ymin,y[i]);
        xmax=imax(xmax,x[i]);
        ymax=imax(ymax,y[i]);
    }
    int w=xmax-xmin+1,h=ymax-ymin+1;
    char g[h*(w+1)+1];
    g[h*(w+1)]='\0';
    for (i=0;i<h;i++) {
        for (j=0;j<w;j++)
            g[i*(w+1)+j]='.';
        g[i*(w+1)+w]='\n';
    }
    for (i=0;i<h;i++)
        g[i*(w+1)-xmin]='|';
    for (i=0;i<w;i++)
        g[ymax*(w+1)+i]='-';
    g[ymax*(w+1)-xmin]='+';
    
    printf("%s",g);
    return 0;
}