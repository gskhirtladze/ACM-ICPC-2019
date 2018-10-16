#include <bits/stdc++.h>

using namespace std;

priority_queue < pair < int , int > >q;
vector < int > g[100020];
int n,i,x,t;
int D[100020];
int f[100020];

int main() {
    freopen("jumping.in","r",stdin);
    cin>>t;
    while (t--) {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            g[i].clear();
        for (i=1;i<=n;i++) {
            scanf("%d",&x);
            if (i+x <= n) g[i+x].push_back(i);
            if (i-x >= 1) g[i-x].push_back(i);
        }
        for (i=1;i<=n;i++)
            D[i]=1000000000,f[i]=0;
        D[n]=0;
        q.push({0,n});
        while (q.size()) {
            int u=q.top().second;
            q.pop();
            if (f[u]) continue;
            f[u]=1;
            for (int i=0;i<g[u].size();i++) {
                int to=g[u][i];
                if (to < 1 || to > n) continue;
                if (D[to] <= D[u]+1) continue;
                D[to]=D[u]+1;
                q.push({-D[to],to});
            }
        }
        for (i=1;i<=n;i++)
            if (D[i] == 1000000000)
                printf("-1\n"); else
                printf("%d\n",D[i]);
    }
}