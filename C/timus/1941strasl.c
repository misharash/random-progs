#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct {
    int b,k;
} buch;
int main() {
    char ssl[32000],skn[4000000];
    scanf("%s%s",ssl,skn);
    int lsl=(strlen(ssl)+1)/4,lkn=(strlen(skn)+1)/4,i,j,kr=0;
    bool r;
    int sl[lsl],kn[lkn];
    buch ch[lsl];
    for (i=0;i<lsl;i++) {
        sl[i]=0;
        for (j=0;j<3;j++) {
            sl[i]*=90;
            sl[i]+=(int)ssl[4*i+j]-33;
        }
        r=true;
        for (j=0;j<kr;j++)
            if (ch[j].b==sl[i]) {
                r=false;
                ch[j].k++;
                break;
            }
        if (r) {
            ch[kr].b=sl[i];
            ch[kr].k=1;
            kr++;
        }
    }
    for (i=0;i<lkn;i++) {
        kn[i]=0;
        for (j=0;j<3;j++) {
            kn[i]*=90;
            kn[i]+=(int)snk[4*i+j]-33;
        }
    }
    
    int kb[729000];