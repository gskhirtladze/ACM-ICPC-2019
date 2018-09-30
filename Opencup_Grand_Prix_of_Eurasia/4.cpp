#include <bits/stdc++.h>

using namespace std;

int n,k,m,a,b,i,j;
vector < int > g[200020];
int P[200020];
map < pair < int , int > , bool > f;
vector < int > ans;

int PP(int u) {
    if (P[u] == u)
        return u;
    P[u]=PP(P[u]);
    return P[u];
}

void uni (int a,int b) {
    if (g[a].size() > g[b].size())
        swap(a,b);
    for (j=0;j<g[a].size();j++) {
        g[b].push_back(g[a][j]);
        f[{b,PP(g[a][j])}]=f[{PP(g[a][j]),b}]=1;
    }
    P[a]=b;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>k>>m;
    for (i=1;i<=k;i++) {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        f[{a,b}]=f[{b,a}]=1;
    }
    for (i=1;i<=n;i++)
        P[i]=i;
    for (i=1;i<=m;i++) {
        scanf("%d%d",&a,&b);
        a=PP(a);
        b=PP(b);
        if (f[{a,b}])
            continue;
        if (a == b) {
            ans.push_back(i);
            continue;
        }
        uni(a,b);
        ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for (i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    cout<<endl;
}