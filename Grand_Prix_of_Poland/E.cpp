#include <bits/stdc++.h>

using namespace std;

int p[100020];
int P[100020][18];
int D[100020][18];
int timer;
int in[100020];
int out[100020];
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

int sz[200020];

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
            sz[u]+=sz[g[u][i].first];
        }
    sz[u]++;
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
pair < pair < int , int > , pair < int , int > > PPP[1000020];

int siz[200020];
int iind[200020];
int pare[200020];
int RT[200020];
int L[1048576];
int R[1048576];
int tr[1048576];
int all;

int HLD(int p,int u,int st) {
    siz[st]++;
    iind[u]=siz[st];
    pare[u]=st;
    int mx=-1,ind=-1;
    for (int i=0;i<g[u].size();i++) {
        if (g[u][i].first == p) continue;
        if (sz[g[u][i].first] > mx) {
            mx=sz[g[u][i].first];
            ind=g[u][i].first;
        }
    }
    for (int i=0;i<g[u].size();i++) {
        if (g[u][i].first == p) continue;
        if (g[u][i].first == ind)
            HLD(u,g[u][i].first,st); else
            HLD(u,g[u][i].first,g[u][i].first);
    }
}

void build(int t,int l,int r) {
    tr[t]=1000000000;
    if (l == r) return;
    L[t]=++all;
    R[t]=++all;
    build(L[t],l,(l+r)/2);
    build(R[t],(l+r)/2+1,r);
}

void segment_upd(int t,int l,int r,int lo,int hi,int z) {
    if (r < lo || hi < l) return;
    if (lo <= l && r <= hi) {
        tr[t]=min(tr[t],z);
        return;
    }
    segment_upd(L[t],l,(l+r)/2,lo,hi,z);
    segment_upd(R[t],(l+r)/2+1,r,lo,hi,z);
}

int MI;

void get_minimum(int t,int l,int r,int X) {
    if (X < l) return;
    if (r < X) return;
    MI=min(MI,tr[t]);
    if (l == r) return;
    get_minimum(L[t],l,(l+r)/2,X);
    get_minimum(R[t],(l+r)/2+1,r,X);
}

int get_num(int x) {
    MI=1000000000;
    get_minimum(RT[pare[x]],1,siz[pare[x]],iind[x]);
    return MI;
}

void make_upd(int x,int y,int z) {
    if (pare[x] == pare[y]) {
        segment_upd(RT[pare[x]],1,siz[pare[x]],iind[y]+1,iind[x],z);
        return;
    }
    segment_upd(RT[pare[x]],1,siz[pare[x]],1,iind[x],z);
    make_upd(P[pare[x]][0],y,z);
}

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
    dfs(0,1,0);
    HLD(0,1,1);
    for (i=1;i<=n;i++) {
        if (siz[i] == 0)
            continue;
        RT[i]=++all;
        build(all,1,siz[i]);
    }
    for (i=1;i<=m;i++)
        if (!f[i]) {
            int k=lca(x[i],y[i]);
            make_upd(x[i],k,z[i]);
            make_upd(y[i],k,z[i]);
        }
    for (i=1;i<=m;i++) {
        if (f[i]) {
            int k=x[i]+y[i]-lca(x[i],y[i]);
            printf("%d\n",get_num(k));
            continue;
        }
        int k=lca(x[i],y[i]);
        printf("%d\n",max(get_max(x[i],k),get_max(y[i],k)));
    }
}