#include <bits/stdc++.h>

using namespace std;
const int maxN = 3e5 + 10000;
map<int, int> mp[maxN];
struct edge {
    int u, v, c;
    bool operator < (const edge &a) {
        return c < a.c;
    }
};
edge e[maxN];
int parent[maxN];
int up[maxN][20];
int vl[maxN][20];
int hg[maxN];
int n, m, q;
vector<pair<int, int> > ed[maxN];
int findset(int v) {
    if (parent[v] == 0) return v;
    parent[v] = findset(parent[v]);
    return parent[v];
}
void dfs(int v, int p) {
    up[v][0] = p;
    for (auto to: ed[v]) {
        if (to.first == p) continue;
        vl[to.first][0] = to.second;
        hg[to.first] = hg[v] + 1;
        dfs(to.first, v);
    }
}
int get(int u, int v) {
    if (hg[u] > hg[v]) swap(u, v);
    int mx = 0;
    for (int j = 16; j >= 0; j--)
        if (hg[up[v][j]] >= hg[u]) {
            mx = max(mx, vl[v][j]);
            v = up[v][j];
        }
    if (u == v) return mx;
    for (int j = 16; j >= 0; j--) {
        if (up[v][j] == up[u][j]) continue;
        mx = max(mx, max(vl[u][j], vl[v][j]));
        v = up[v][j]; u = up[u][j];
    }
    mx = max(mx, max(vl[u][0], vl[v][0]));
    return mx;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        if (u > v) swap(u, v);
        mp[u][v] = c;
        e[i].u = u; e[i].v = v; e[i].c = c;
    }
    sort(e + 1, e + m + 1);
    long long sum = 0;
    for (int i = 1; i <= m; i++) {
        int u = findset(e[i].u);
        int v = findset(e[i].v);
        if (u == v) continue;
        sum += e[i].c;
        ed[e[i].u].push_back(make_pair(e[i].v, e[i].c));
        ed[e[i].v].push_back(make_pair(e[i].u, e[i].c));
        parent[v] = u;
    }
    cout<<" S"<<sum<<endl;
    hg[0] = -1;
    dfs(1, 0);
    for (int j = 1; j < 17; j++)
    for (int i = 1; i <= n; i++) up[i][j] = up[up[i][j - 1]][j - 1], vl[i][j] = max(vl[up[i][j - 1]][j - 1], vl[i][j - 1]);
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        int cost = mp[u][v];
        int mx = get(u, v);
        cout << sum - mx + cost <<" "<<mx<< "\n";
    }
    return 0;

}