#include <iostream>
using namespace std;
int main() {
    int n,j;
    cin >> n;
    int kk=n,k,i,ks[n];
    long long s[n],sc,psc;
    for (i=0;i<n;i++)
        ks[i]=0;
    for (j=0;j<n;j++)
        cin >> s[j];
    for (i=0;i<2;i++) {
        cin >> n;
        psc=-100;
        for (j=0;j<n;j++) {
            cin >> sc;
            for (k=0;k<kk;k++)
                if (sc==s[k]) {
                    if (sc!=psc)
                        ks[k]++;
                    break;
                }
            psc=sc;
        }
    }
    k=0;
    for (i=0;i<n;i++)
        if (ks[i]>=2)
            k++;
    cout << k << endl;
    return 0;
}