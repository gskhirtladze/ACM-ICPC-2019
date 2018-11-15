#include <bits/stdc++.h>

using namespace std;

int p[500020];
vector < int > g[500020];
int PP[19][500020];
int tot[500020];
int f[500020];

int P(int u) {
    if (p[u] == u) return u;
    p[u]=P(p[u]);
    return p[u];
}

void uni(int x,int y) {
    g[x].push_back(y);
    g[y].push_back(x);
    x=P(x);
    y=P(y);
    p[x]=y;
}

int timer;
int in[500020];
int out[500020];

void dfs(int p,int u) {
    timer++;
    in[u]=timer;
    f[u]=1;
    PP[0][u]=p;
    for (int i=1;i<19;i++)
        PP[i][u]=PP[i-1][PP[i-1][u]];
    for (int i=0;i<g[u].size();i++)
        if (g[u][i] != p) dfs(u,g[u][i]);
    out[u]=timer;
}

void fix(int p,int u) {
    f[u]=1;
    for (int i=0;i<g[u].size();i++)
        if (g[u][i] != p) { fix(u,g[u][i]); tot[u]+=tot[g[u][i]]; }
}

int n,m,i;
int x[500020];
int y[500020];

int lca(int a,int b) {
    if (in[a] <= in[b] && out[b] <= out[a]) return a;
    for (int i=18;i>=0;i--)
        if (PP[i][a])
            if (!(in[PP[i][a]] <= in[b] && out[b] <= out[PP[i][a]]))
                a=PP[i][a];
    return PP[0][a];
}


vector < int > gg[500020];
vector < int > gr[500020];
vector < int > order,component;
int comp[500020];

void dfs1 (int v) {
	f[v] = true;
	for (size_t i=0; i<gg[v].size(); ++i)
		if (!f[ gg[v][i] ])
			dfs1 (gg[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	f[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!f[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

int main() {
    cin>>n>>m;
    for (i=1;i<=m;i++) {
        scanf("%d%d",&x[i],&y[i]);
        gg[x[i]].push_back(y[i]);
        gr[y[i]].push_back(x[i]);
    }
    for (i=1;i<=n;i++)
        f[i]=0;
    for (i=1;i<=n;i++)
        if (!f[i])
            dfs1(i);
    for (i=1;i<=n;i++)
        f[i]=0;
    for (i=0;i<n;i++) {
        int v=order[n-i-1];
        if (!f[v]) {
            dfs2(v);
            for (int j=0;j<component.size();j++)
                comp[component[j]]=v;
            component.clear();
        }
    }
    for (i=1;i<=n;i++)
        p[i]=i;
    for (i=1;i<=m;i++) {
        if (comp[x[i]] != comp[y[i]])
            continue;
        if (P(x[i]) != P(y[i])) {
            uni(x[i],y[i]);
        }
    }
    for (i=1;i<=n;i++)
        f[i]=0;
    for (i=1;i<=n;i++)
        if (!f[i]) dfs(0,i);
    for (i=1;i<=m;i++) {
        if (comp[x[i]] != comp[y[i]])
            continue;
        tot[x[i]]++;
        tot[y[i]]++;
        tot[lca(x[i],y[i])]-=2;
    }
    for (i=1;i<=n;i++)
        f[i]=0;
    for (i=1;i<=n;i++)
        if (!f[i])
            fix(0,i);
    for (i=1;i<=n;i++)
        if (tot[i] > 2) {
            cout<<"NO"<<endl;
            return 0;
        }
    cout<<"YES"<<endl;
}