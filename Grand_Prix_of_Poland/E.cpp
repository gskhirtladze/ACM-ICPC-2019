#include <bits/stdc++.h>

using namespace std;

int p[100020];
int P[200020][18];
int D[200020][18];
int timer;
int in[20020];
int out[20020];
vector < pair < int , int > > g[100020];

int PP(int a) {
    if (a == p[a])
        return a;
    p[a]=PP(p[a]);
    return p[a];
}

void uni(int a,int b,int c) {
    if (PP(a) == PP(b)) return;
    g[a].push_back({b,c});
    g[b].push_back({a,c});
    p[PP(a)]=PP(b);
}

void dfs(int p,int u,int c) {
    P[u][0]=p;
    D[u][0]=c;
    for (int i=1;i<=17;i++)
        P[u][i]=P[P[u][i-1]][i-1],
        D[u][i]=max(D[u][i-1],D[P[u][i-1]][i-1]);
    ++timer;
    in[u]=timer;
    for (int i=0;i<g[u].size();i++)
        if (g[u][i].first != p) {
            dfs(u,g[u][i].first,g[u][i].second);
        }
    out[u]=timer;
}

int lca(int a,int b) {
    if (in[a] <= in[b] && out[b] <= out[a]) return a;
    for (int i=17;i>=0;i--)
        if (P[a][i])
            if (!(in[P[a][i]] <= in[b] && out[b] <= out[P[a][i]]))
                a=P[a][i];
    return P[a][0];
}

int get_max(int x,int y) {
    int res=0;
    for (int i=17;i>=0;i--)
        if (P[x][i])
            if (!(in[P[x][i]] <= in[y] && out[y] <= out[P[x][i]])) {
                res=max(res,D[x][i]);
                x=P[x][i];
            }
    if (x != y)
        res=max(res,D[x][0]);
    return res;
}

int n,m,i;
int x[1000020];
int y[1000020];
int z[1000020];
int f[1000020];
pair < pair < int , int > , pair < int , int > > PPP[200020];

#define f_sum(i,r) for (int i=r;i>=0;i=(i&(i+1))-1)
#define f_upd(i,r) for (;i<=r;i=(i|(i+1)))
map < int , int > mx[100020];

int main() {
    cin>>n>>m;
    for (i=1;i<=m;i++) {
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        PPP[i].first={z[i],i};
        PPP[i].second={x[i],y[i]};
    }
    for (i=1;i<=n;i++)
        p[i]=i;
    sort(PPP+1,PPP+m+1);
    for (i=1;i<=m;i++)
        if (PP(PPP[i].second.first) != PP(PPP[i].second.second)) {
            f[PPP[i].first.second]=1;
            uni(PPP[i].second.first,PPP[i].second.second,PPP[i].first.first);
        }
    for (i=1;i<=m;i++)
        if (!f[i]) {
        int k=lca(x[i],y[i]);
        inse[x[i]].push_back(z[i]);
        inse[y[i]].push_back(z[i]);
        era[k].push_back(z[i]);
        }
    dfs(0,1,0);
    for (i=1;i<=m;i++) {
        if (f[i]) {
            int k=x[i]+y[i]+lca(x[i],y[i]);
            printf("%d\n",mx[k]);
            continue;
        }
        int k=lca(x[i],y[i]);
        printf("%d\n",max(get_max(x[i],k),get_max(y[i],k)));
    }
}