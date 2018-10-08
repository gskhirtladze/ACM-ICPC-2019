#include <bits/stdc++.h>

#define X second.first
#define Y second.second

using namespace std;

int p[200020];
vector < int > g[200020];
vector < int > s[200020];

int PP(int u) {
    if (u == p[u]) return u;
    p[u]=PP(p[u]);
    return p[u];
}

void uni(int a,int b,int c) {
    g[a].push_back(b);
    g[b].push_back(a);
    s[a].push_back(c);
    s[b].push_back(c);
    a=PP(a); b=PP(b);
    p[a]=b;
}

pair < int , pair < int , int > > P[200020];
int pa[100020][17];
int pc[100020][17];
int n,m,i;
long long ans;

int in[200020];
int out[200020];
int timer;

void dfs(int p,int u,int cs) {
    pa[u][0]=p;
    pc[u][0]=cs;
    ++timer;
    in[u]=timer;
    for (int i=1;i<17;i++)
        pa[u][i]=pa[ pa[u][i-1] ][i-1],
        pc[u][i]=max(pc[u][i-1],pc[ pa[u][i-1] ][i-1]);
    for (int i=0;i<g[u].size();i++)
        if (g[u][i] != p) dfs(u,g[u][i],s[u][i]);
    out[u]=timer;
}

int mx,q;

void lca(int a,int b) {
    if (in[a] <= in[b] && out[b] <= out[a]) return;
    for (int i=16;i>=0;i--)
        if (pa[a][i])
            if (!(in[pa[a][i]] <= in[b] && out[b] <= out[pa[a][i]]))
                mx=max(mx,pc[a][i]),a=pa[a][i];
    mx=max(mx,pc[a][0]);
}

map < pair < int , int > ,int  > cst;

int main() {
    cin>>n>>m;
    for (i=1;i<=m;i++)
        scanf("%d%d%d",&P[i].X,&P[i].Y,&P[i].first),
        cst[{P[i].X,P[i].Y}]=P[i].first;
    sort(P+1,P+m+1);
    for (i=1;i<=n;i++)
        p[i]=i;
    for (i=1;i<=m;i++)
        if (PP(P[i].X) != PP(P[i].Y)) {
            ans+=P[i].first;
            uni(P[i].X,P[i].Y,P[i].first);
        }
    dfs(0,1,0);
    cin>>q;
    while (q--) {
        int a,b;
        scanf("%d%d",&a,&b);
        mx=0;
        lca(a,b);
        lca(b,a);
        cout<<ans-mx+cst[{a,b}]<<endl;
    }
}