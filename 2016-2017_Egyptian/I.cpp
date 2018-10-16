#include <bits/stdc++.h>

using namespace std;

int x,y,r,n,m,i,t;
vector < pair < double , int > > all;

int main() {
    freopen("walk.in","r",stdin);
    cin>>t;
    while (t--) {
        scanf("%d%d",&n,&m);
        all.clear();
        for (i=1;i<=n;i++) {
            scanf("%d%d%d",&x,&y,&r);
            if (y<0) y*=-1;
            if (y+r > m) continue;
            double dst=sqrt(1.0*(m-r)*(m-r)-1.0*y*y);
            all.push_back({x-dst-0.0000001,+r});
            all.push_back({x+dst+0.0000001,-r});
        }
        sort(all.begin(),all.end());
        int ans=0,now=0;
        for (int i=0;i<all.size();i++)
            now+=all[i].second,ans=max(ans,now);
        cout<<ans<<endl;
    }
}