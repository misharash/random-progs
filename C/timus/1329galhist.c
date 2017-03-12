#include <stdio.h>
int main() {
    unsigned int n;
    scanf("%d",&n);
    unsigned int i;
    long int id,pid,v[40010],nm[40010];
    for (i=0;i<n;i++) {
        scanf("%ld%ld",&id,&pid);
        v[id]=pid;
        nm[id]=i;
    }
    unsigned int l;
    scanf("%d",&l);
    long int a,b,pp;
    for (i=0;i<l;i++) {
        scanf("%ld%ld",&a,&b);
        if (nm[a]>nm[b]) {
        pp=a;
        while ((v[pp]!=-1)&&(v[pp]!=b)) {
            pp=v[pp];
        }
        if (v[pp]==b)
            printf("2\n");
        else {
            pp=b;
            while ((v[pp]!=-1)&&(v[pp]!=a)) {
                pp=v[pp];
            }
            if (v[pp]==a)
                printf("1\n");
            else
                printf("0\n");
        }
        }
        else {
        pp=b;
        while ((v[pp]!=-1)&&(v[pp]!=a)) {
            pp=v[pp];
        }
        if (v[pp]==a)
            printf("1\n");
        else {
            pp=a;
            while ((v[pp]!=-1)&&(v[pp]!=b)) {
                pp=v[pp];
            }
            if (v[pp]==b)
                printf("2\n");
            else
                printf("0\n");
        }
        }
    }
    return 0;
}