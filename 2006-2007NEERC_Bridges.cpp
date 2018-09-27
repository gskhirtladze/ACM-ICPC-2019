#include <bits/stdc++.h>

using namespace std;

vector < pair < int , int > > g[20020];
long long load[200020];
long long sz[200020];
int p[200020];
int sh,sc;
int x[200020];
int n,k,i,a,b;

void dfs(int p,int u,int LL) {
    for (int i=0;i<g[u].size();i++)
        if (g[u][i].first != p) {
            dfs(u,g[u][i].first,g[u][i].second);
            sz[u]+=sz[g[u][i].first];
        }
    sz[u]++;
    load[LL]=1LL*sz[u]*(n-sz[u]);
}

bool tmp(int a,int b) {
    return ( 1LL*x[a]*load[a] > 1LL*x[b]*load[b] );
}

int main() {
    cin>>n>>k>>sh>>sc;
    for (i=1;i<=n-1;i++) {
        scanf("%d%d%d",&a,&b,&x[i]);
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    dfs(0,1,0);
    for (i=1;i<=n-1;i++)
        p[i]=i;
    sort(p+1,p+n,tmp);
    if (sh > sc) reverse(p+1,p+n);
    for (i=1;i<=k;i++)
        printf("%d ",p[i]);
    cout<<endl;
}