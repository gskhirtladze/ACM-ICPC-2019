#include <bits/stdc++.h>

using namespace std;

long long t,n,k,i;
long long a[200020];
long long l,r,m,ans;

int main() {
    cin>>t;
    for (int it=1;it<=t;it++) {
        cin>>n>>k;
        for (i=1;i<=n;i++)
            cin>>a[i];
        l=1; r=100000000000000LL; ans=0;
        while (l <= r) {
            m=(l+r)/2;
            long long tot=0;
            long long lef=0;
            for (i=1;i<=n;i++)
                if (a[i] >= m) {
                    tot++;
                    continue;
                } else
                lef+=a[i];
            if (lef/m+tot >= k) {
                ans=m;
                l=m+1;
            } else r=m-1;
        }
        cout<<"Case "<<it<<": "<<ans<<endl;
    }
}