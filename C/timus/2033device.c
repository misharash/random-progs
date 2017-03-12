#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 6
typedef struct {
    char name[30];
    int price,count;
} device;
bool dcmp(device* d1,device* d2) {
    if (!strcmp((*d1).name,(*d2).name)) {
        (*d1).count++;
        if ((*d1).price>(*d2).price)
            (*d1).price=(*d2).price;
        return true;
    }
    return false;
}
device cloned(device a) {
    device d;
    strcpy(d.name,a.name);
    d.price=a.price;
    d.count=a.count;
    return d;
}
int main() {
    device d[N],dc;
    int i,j,count=0;
    char name[30];
    bool f;
    for (i=0;i<N;i++) {
        scanf("%s%s%d",name,dc.name,&dc.price);
        dc.count=1;
        f=false;
        for (j=0;j<count;j++)
            f=f||dcmp(&d[j],&dc);
        if (!f) {
            d[count]=cloned(dc);
            count++;
        }
    }
    dc=d[0];
    for (i=1;i<count;i++) {
        if (dc.count<d[i].count)
            dc=d[i];
        else
            if (dc.count==d[i].count)
                if (dc.price>d[i].price)
                    dc=d[i];
    }
    printf("%s\n",dc.name);
    return 0;
}
