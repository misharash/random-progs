#include <stdio.h>
int main() {
    char s[2000000];
    int i,c,pn[37],n[37],k[37],j;
    for (i=2;i<37;i++) {
        n[i]=0;
        k[i]=0;
    }
    while (gets(s)) {
        for (j=0;s[j]!='\0';j++) {
            if ((s[j]>='0')&&(s[j]<='9'))
                c=(int)s[j]-48;
            else
                if ((s[j]>='A')&&(s[j]<='Z'))
                    c=(int)s[j]-55;
                else
                    c=37;
            for (i=2;i<37;i++) {
                pn[i]=n[i];
                if (c<i)
                    n[i]=1;
                else
                    n[i]=0;
                //printf("%d %d %d\n",j,i,n[i]);
                if ((!(pn[i]))&&(n[i]))
                    k[i]++;
            }
        }
        for (i=2;i<37;i++)
            n[i]=0;
    }
    int imax=2;
    for (i=3;i<37;i++) {
        //printf("%d %d\n",i,k[i]);
        if (k[i]>k[imax])
            imax=i;
    }
    printf("%d %d\n",imax,k[imax]);
    return 0;
}
