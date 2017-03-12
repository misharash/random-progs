#include <iostream>
using namespace std;
int main() {
    int n,i;
    cin >> n;
    long long t[n+1];
    t[0]=0;
    t[1]=2;
    for (i=2;i<=n;i++)
        t[i]=t[i-1]+t[i-2];
    cout << t[n] << endl; //идеально
    return 0;
}