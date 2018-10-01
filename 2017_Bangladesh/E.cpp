#include <bits/stdc++.h>

using namespace std;

long long ans;
int all[200020];
int t,n,i,x;

int main() {
    cin>>t;
    while (t--) {
        for (i=1;i<=100000;i++)
            all[i]=0;
        cin>>n;
        ans=0;
        for (i=1;i<=n;i++) {
            scanf("%d",&x);
            all[x]++;
        }
        for (i=1;i<=100000;i++) {
            ans+=1ll*all[i]*(n-all[i]);
        }
        ans/=2;
        for (i=1;i<=100000;i++)
            if (all[i] >= 2) {
                ans++;
                break;
        }
        cout<<ans<<endl;
    }
}