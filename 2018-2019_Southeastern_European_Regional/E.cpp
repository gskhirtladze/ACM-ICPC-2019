#include <bits/stdc++.h>

using namespace std;

int n,m,x,y,i,l;
vector < pair < int , int > > all;

int main() {
    cin>>n>>m>>l;
    for (i=1;i<=n;i++) {
        scanf("%d%d",&x,&y);
        if (y > l) continue;
        int t=x-l+y;
        all.push_back({t,+1});
        t=x+l-y;
        all.push_back({t+1,-1});
    }
    sort(all.begin(),all.end());
    for (i=1;i<all.size();i++)
        all[i].second+=all[i-1].second;
    for (i=1;i<=m;i++) {
        scanf("%d",&x);
        int l=0; int r=all.size()-1; int ans=0;
        while (l <= r) {
            int mi=(l+r)/2;
            if (all[mi].first <= x) {
                ans=all[mi].second;
                l=mi+1;
            } else r=mi-1;
        }
        printf("%d\n",ans);
    }
}