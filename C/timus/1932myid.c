#include <stdio.h>
int main() {
    unsigned int n;
    scanf("%d",&n);
    //printf("%d",n);
    unsigned int a,i;
    short unsigned int c[n][4],e[16][16][16][16],cc[4];
    for (cc[0]=0;cc[0]<16;cc[0]++)
        for (cc[1]=0;cc[1]<16;cc[1]++)
            for (cc[2]=0;cc[2]<16;cc[2]++)
                for (cc[3]=0;cc[3]<16;cc[3]++)
                    e[cc[0]][cc[1]][cc[2]][cc[3]]=0;
    for (i=0;i<n;i++) {
        scanf("%x",&a);
        //printf("%d\n",a);
        c[i][0]=a/4096;
        c[i][1]=(a/256)%16;
        c[i][2]=(a/16)%16;
        c[i][3]=a%16;
        //printf("%d %d %d %d\n",c[i][0],c[i][1],c[i][2],c[i][3]);
        e[c[i][0]][c[i][1]][c[i][2]][c[i][3]]=1;
    }
    short unsigned int k[5]={0,0,0,0,0};
    //printf("%d %d %d %d\n",k[3],k[2],k[1],k[0]);
    short unsigned int kk=0;
    for (i=0;i<n;i++) {
        cc[0]=c[i][0];
        for (cc[1]=0;cc[1]<16;cc[1]++) {
            for (cc[2]=0;cc[2]<16;cc[2]++) {
                for (cc[3]=0;cc[3]<16;cc[3]++) {
                    kk=1;
                    if (cc[1]==c[i][1])
                        kk++;
                    if (cc[2]==c[i][2])
                        kk++;
                    if (cc[3]==c[i][3])
                        kk++;
                    k[kk]+=e[cc[0]][cc[1]][cc[2]][cc[3]];
                    //printf("%d\n",k[kk]);
                }
            }
        }
        cc[1]=c[i][1];
        for (cc[0]=0;cc[0]<16;cc[0]++) {
            for (cc[2]=0;cc[2]<16;cc[2]++) {
                for (cc[3]=0;cc[3]<16;cc[3]++) {
                    kk=1;
                    if (cc[0]==c[i][0])
                        kk++;
                    if (cc[2]==c[i][2])
                        kk++;
                    if (cc[3]==c[i][3])
                        kk++;
                    k[kk]+=e[cc[0]][cc[1]][cc[2]][cc[3]];
                    //printf("%d\n",k[kk]);
                }
            }
        }
        cc[2]=c[i][2];
        for (cc[1]=0;cc[1]<16;cc[1]++) {
            for (cc[0]=0;cc[0]<16;cc[0]++) {
                for (cc[3]=0;cc[3]<16;cc[3]++) {
                    kk=1;
                    if (cc[1]==c[i][1])
                        kk++;
                    if (cc[0]==c[i][0])
                        kk++;
                    if (cc[3]==c[i][3])
                        kk++;
                    k[kk]+=e[cc[0]][cc[1]][cc[2]][cc[3]];
                    //printf("%d\n",k[kk]);
                }
            }
        }
        cc[3]=c[i][3];
        for (cc[1]=0;cc[1]<16;cc[1]++) {
            for (cc[2]=0;cc[2]<16;cc[2]++) {
                for (cc[0]=0;cc[0]<16;cc[0]++) {
                    kk=1;
                    if (cc[1]==c[i][1])
                        kk++;
                    if (cc[2]==c[i][2])
                        kk++;
                    if (cc[0]==c[i][0])
                        kk++;
                    k[kk]+=e[cc[0]][cc[1]][cc[2]][cc[3]];
                    //printf("%d\n",k[kk]);
                }
            }
        }
    }
    //printf("%d %d %d %d\n",k[3],k[2],k[1],k[0]);
    k[1]/=2;
    k[2]/=4;
    k[3]/=6;
    k[0]=n*(n-1)/2-k[1]-k[2]-k[3];
    printf("%d %d %d %d\n",k[3],k[2],k[1],k[0]);
    return 0;
}