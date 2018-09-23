#include <bits/stdc++.h>

using namespace std;

long long t,n,i;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        n/=6;
        for (i=1;i*i<=n;i++);
        cout<<i-1<<endl;
    }
}