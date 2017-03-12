#include <stdio.h>
int daynum(int d,int m,int y) {
    long r=d;
    int i;
    for (i=1600;i<y;i++) {
        r+=365;
        if ((!(i%4))&&(i%100))
            r+=1;
        if (!(i%400))
            r+=1;
    }
    for (i=1;i<m;i++) {
        if ((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12))
            r+=31;
        if ((i==4)||(i==6)||(i==9)||(i==11))
            r+=30;
        if (i==2) {
            r+=28;
            if ((!(y%4))&&(y%100))
                r+=1;
            if (!(y%400))
                r+=1;
        }
    }
    return r;
}
int mdays(int m,int y) {
    int r;
    if ((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
        r=31;
    if ((m==4)||(m==6)||(m==9)||(m==11))
        r=30;
    if (m==2) {
        r=28;
        if ((!(y%4))&&(y%100))
            r+=1;
        if (!(y%400))
            r+=1;
    }
    return r;
}
int bdiv(int a,int b) {
    int r=a/b;
    if (a%b)
        r++;
    return r;
}
int main() {
    int d,m,y,i,j,t;
    scanf("%d%d%d",&d,&m,&y);
    int s=(daynum(1,m,y)+4)%7-1,dm=mdays(m,y),w=bdiv(s+dm+1,7),len=5*w+2,cd;
    //printf("%d %d %d %d\n",s,dm,w,len);
    char c[7][50]={"mon","tue","wed","thu","fri","sat","sun"},buf[10],sep=' ';
    for (i=0;i<7;i++) {
        for (j=3;j<len;j++)
            c[i][j]=sep;
        c[i][len]='\0';
        c[i][len+1]='\0';
        //printf("%s\n",&c[i]);
    }
    for (i=0;i<w;i++) {
        for (j=0;j<7;j++) {
            cd=7*i+j-s;
            if ((cd>0)&&(cd<=dm)) {
                sprintf(&c[j][5*i+5],"%2d",cd);
                if (i!=w-1)
                    c[j][5*i+7]=sep;
                //printf("%2d\n",cd);
                //sprintf(buf,"%2d",cd);
                if (cd==d) {
                    c[j][5*i+4]='[';
                    c[j][5*i+7]=']';
                }
            }
        }
    }
    for (i=0;i<7;i++)
        printf("%s\n",&c[i]);
    return 0;
}