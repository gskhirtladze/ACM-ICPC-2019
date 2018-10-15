#include <bits/stdc++.h>

using namespace std;
int t,n,ans;
int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        ans+=(n!=1);
    }
    cout<<ans<<endl;
}