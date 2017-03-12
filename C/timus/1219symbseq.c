#include <stdio.h>
#include <string.h>
int main() {
    char s[1000010]="ab";
    short n[1000010];
    n[0]=0;
    n[1]=1;
    int k1[26],k2[26][26],k3[26][26][26];
    int i1,i2,i3;
    for (i1=0;i1<26;i1++) {
        k1[i1]=0;
        for (i2=0;i2<26;i2++) {
            k2[i1][i2]=0;
            for (i3=0;i3<26;i3++)
                k3[i1][i2][i3]=0;
        }
    }
    k1[0]=1;
    k1[1]=1;
    k2[0][1]=1;
    int i,c;
    for (i=2;i<1000000;i++) {
        c=0;
        while ((k1[c]>=40000)||(k2[n[i-1]][c]>=2000)||(k3[n[i-2]][n[i-1]][c]>=100))
            c++;
        if (c>25) {
            printf("OH SHI~\nposition %d\n",i+1);
            return 0;
        }
        n[i]=c;
        s[i]=(char)(97+c);
        k1[c]++;
        k2[n[i-1]][c]++;
        k3[n[i-2]][n[i-1]][c]++;
    }
    s[1000000]=(char) 0;
    printf("%s",s);
    return 0;
}