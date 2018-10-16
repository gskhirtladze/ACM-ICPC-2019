#include <bits/stdc++.h>

using namespace std;

int t,n,m,c,x,y,p,i;
vector < pair < long long , long long  > > all[400020];

int main() {
    freopen("bishops.in","r",stdin);
    cin>>t;
    while (t--) {
        cin>>n>>m>>c;
        for (i=1;i<=m;i++) {
            scanf("%d%d%d",&x,&y,&p);
            all[x-y+n].push_back({y*2+2LL*p*p+c-1,y*2-2LL*p*p-c+1});
            all[x+y+2*n].push_back({y*2+2LL*p*p+c-1,y*2-2LL*p*p-c+1});
        }
        int tot=1;
        for (i=1;i<=4*n;i++) {
            sort(all[i].begin(),all[i].end());
            vector < int > ans;
            ans.push_back(1);
            int res=0;
            for (int j=1;j<all[i].size();j++) {
                int lo=0,hi=j-1,mi=0,res=ans[j-1];
                while (lo <= hi) {
                    mi=(lo+hi)/2;
                    if (all[i][mi].first <= all[i][j].second) {
                        lo=mi+1;
                        res=max(res,ans[mi]+1);
                    } else hi=mi-1;
                }
                ans.push_back(res);
                tot=max(tot,res);
            }
            all[i].clear();
        }
        cout<<tot<<endl;
    }
}