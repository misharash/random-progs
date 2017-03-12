#include <iostream>
using namespace std;
int main() {
    long long fac[11];
    int i;
    fac[0]=1;
    for (i=1;i<11;i++)
        fac[i]=i*fac[i-1];
    int n;
    long long k;
    cin >> n;
    while (n!=-1) {
        k=fac[n]+1;
        for (i=2;i<n;i++)
            k+=(fac[n]*(n-i+1))/fac[i]; // C_n^k*P_{n-k+1}=n!/k!(n-k)!*(n-k+1)!
        cout << k << endl;
        cin >> n;
    }
    return 0;
}