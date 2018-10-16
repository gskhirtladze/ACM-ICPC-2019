#include <bits/stdc++.h>

using namespace std;

int P[5000001][19];
int ans[5000001];
int sum[5000001];
vector < pair < int , int > > g[5000001];

void dfs(int p,int u,int c) {
    P[u][0]=p;
    sum[u]=sum[p]+c;
    if (sum[u] > 1000000001) sum[u]=1000000001;
    for (int i=1;i<=18;i++)
        P[u][i]=P[P[u][i-1]][i-1];
    int st=u;
    for (int i=18;i>=0;i--)
        if (P[st][i] && sum[u]-sum[P[st][i]] <= ans[u]) {
            st=P[st][i];
        }
    ans[u]=0;
    ans[u]++;
    ans[P[st][0]]--;
    for (int i=0;i<g[u].size();i++)
        if (g[u][i].first != p)
            dfs(u,g[u][i].first,g[u][i].second),
            ans[u]+=ans[g[u][i].first];
}

int t,n,i,x,b,c;

int main() {
    freopen("car.in","r",stdin);
    cin>>t;
    while (t--) {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            g[i].clear(),scanf("%d",&ans[i]);
        for (i=1;i<n;i++) {
            scanf("%d%d%d",&x,&b,&c);
            g[x].push_back({b,c});
            g[b].push_back({x,c});
        }
        dfs(0,1,0);
        for (i=1;i<=n;i++)
            printf("%d ",ans[i]-1);
        printf("\n");
    }
}