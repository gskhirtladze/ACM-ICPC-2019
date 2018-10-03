#include <bits/stdc++.h>

using namespace std;

long long ans=0;
vector < int > all;
int a[3];
int t,k,n,i;

int main() {
    cin>>t;
    while (t--) {
        scanf("%d%d",&n,&k);
        for (i=1;i<=n;i++) {
            scanf("%d%d%d",&a[0],&a[1],&a[2]);
            sort(a,a+3);
            all.push_back(a[0]);
            all.push_back(a[1]);
        }
        sort(all.begin(),all.end());
        for (int i=0;i<k;i++)
            ans+=all[i];
        cout<<ans<<endl;
        all.clear();
        ans=0;
    }
}