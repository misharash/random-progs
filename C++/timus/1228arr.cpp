#include <iostream>
using namespace std;
int main() {
    int n,i;
    cin >> n;
    long long k,pk,v[n];
    cin >> k;
    for (i=0;i<n;i++) {
        pk=k;
        cin >> k;
        v[i]=pk/k-1;
    }
    for (i=0;i<n-1;i++)
        cout << v[i] << " ";
    cout << v[n-1] << endl;
    return 0;
}