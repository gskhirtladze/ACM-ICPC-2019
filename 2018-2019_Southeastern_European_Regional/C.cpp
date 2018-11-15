#include <bits/stdc++.h>

using namespace std;

int dst[1002][1002];
vector < int > g[10002];
int a[10002];
int x,y,n,m,res,i;
vector < int > all;

void dfs(int p,int u) {
    dst[i][u]=dst[i][p]+1;
    for (int ii=0;ii<g[u].size();ii++)
        if (g[u][ii] != p)
            dfs(u,g[u][ii]);
}

int main() {
    cin>>n>>m;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<n;i++) {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (m == 1) {
        cout<<0<<endl;
        return 0;
    }
    res=n;
    for (i=1;i<=n;i++) {
        dst[i][0]=-1;
        dfs(0,i);
    }
    for (i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++) {
            int tot=0;
            for (int k=1;k<=n;k++)
                if (a[k] && max(dst[k][i],dst[k][j]) <= dst[i][j]) tot++;
            if (tot >= m) res=min(res,dst[i][j]);
        }
    cout<<res<<endl;
}