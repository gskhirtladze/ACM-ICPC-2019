#include <bits/stdc++.h>

using namespace std;
int t;
int main() {
    freopen("popcorn.in","r",stdin);
    cin>>t;
    while (t--) {
        int n,m,i;
        cin>>n>>m;
        long long ans=1;
        int a=m,b=n-m;
        if (a<b) swap(a,b);
        for (i=a+1;i<=n;i++)
            ans*=i;
        for (i=1;i<=b;i++)
            ans/=i;
        cout<<ans<<endl;
    }
}