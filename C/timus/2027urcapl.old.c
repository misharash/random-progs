#include <stdio.h>
int main() {
    int h,w;
    scanf("%d%d",&h,&w);
    char code[h][w+1];
    int i;
    for (i=0;i<h;i++)
        scanf("%s",code[i]);
    i=0;
    int j=0;
    int fi=0,fj=1,ri=1,rj=0; //front, right
    int c[26],cc=0; //cells and current cell
    int b,bb,rn; //buff, register number
    int k;
    long t=0;
    for (k=0;k<26;k++)
        c[k]=0;
    scanf("%d",&k);
    int in[k];
    int p;
    for (p=0;p<k;p++)
        scanf("%d",&in[p]);
    p=0;
    while (t<1000000) {
        if (code[i][j]=='#')
            return 0;
        if (code[i][j]=='^') {
            fi=-1;
            fj=0;
            ri=0;
            rj=1;
        }
        else {
            if (code[i][j]=='v') {
                fi=1;
                fj=0;
                ri=0;
                rj=-1;
            }
            else {
                if (code[i][j]=='>') {
                    fi=0;
                    fj=1;
                    ri=1;
                    rj=0;
                }
                else {
                    if (code[i][j]=='<') {
                        fi=0;
                        fj=-1;
                        ri=-1;
                        rj=0;
                    }
                    else {
                        if ((code[i][j]>='A')&&(code[i][j]<='Z')) {
                            rn=((int) code[i][j])-65;
                            b=cc;
                            cc=c[rn];
                            c[rn]=b;
                        }
                        else {
                            if (code[i][j]=='?') {
                                cc=in[p];
                                if (p<k-1)
                                    p++;
                            }
                            else {
                                if (code[i][j]=='!') {
                                    printf("%d\n",cc);
                                    cc=0;
                                }
                                else {
                                    if (code[i][j]=='@') {
                                        b=fi;
                                        bb=fj;
                                        if (cc) {
                                            fi=ri;
                                            fj=rj;
                                            ri=-b;
                                            rj=-bb;
                                        }
                                        else {
                                            fi=-ri;
                                            fj=-rj;
                                            ri=b;
                                            rj=bb;
                                        }
                                    }
                                    else {
                                        if (code[i][j]=='+')
                                            cc++;
                                        else {
                                            if (code[i][j]=='-')
                                                cc--;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((cc>100000)||(cc<-100000)) {
            printf("OVERFLOW ERROR\n");
            return 0;
        }
        i+=fi;
        j+=fj;
        if ((i>=h)||(i<0)||(j>=w)||(i<0)) {
            printf("RUNTIME ERROR\n");
            return 0;
        }
        t++;
    }
    printf("TIME LIMIT EXCEEDED\n");
    return 0;
}
