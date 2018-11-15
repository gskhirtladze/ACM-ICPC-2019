#include <bits/stdc++.h>

using namespace std;

int n,a,ans,i;
int f[200020];
int main() {
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a,f[a]++;
    for (i=1;i<=n;i++) {
        cin>>a;
        if (f[a]) { ans++; f[a]--;}
    }
    cout<<n-ans<<endl;
}