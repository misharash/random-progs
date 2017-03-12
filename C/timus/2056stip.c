#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int min=5,sum=0,i,o;
    for (i=0;i<n;i++) {
        scanf("%d",&o);
        if (o<min)
            min=o;
        sum+=o;
    }
    if (min<=3)
        printf("None\n");
    else {
        if (min>=5)
            printf("Named\n");
        else {
            if (2*sum>=9*n)
                printf("High\n");
            else
                printf("Common\n");
        }
    }
    return 0;
}