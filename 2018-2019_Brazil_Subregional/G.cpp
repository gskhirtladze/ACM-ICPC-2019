#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100020;
const int INF = 1000000000; 

struct edge {
	int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

int p,r,c,i,sum;
int pp[100020];
int rr[100020];
int lo,hi,mi,ans;
pair < int ,pair < int , int > > P[100020];

int main() {
    cin>>p>>r>>c;
    for (i=1;i<=p;i++)
        cin>>pp[i],sum+=pp[i];
    for (i=1;i<=r;i++)
        cin>>rr[i];
    for (i=1;i<=c;i++)
        cin>>P[i].second.first>>P[i].second.second>>P[i].first;
    sort(P+1,P+c+1);
    lo=1; hi=c; ans=0;
    n=1+p+r+1;
    while (lo <= hi) {
        mi=(lo+hi)/2;
        for (int i=0;i<n;i++)
            g[i].clear();
        e.clear();
        for (int i=1;i<=r;i++)
            add_edge(0,i,rr[i]);
        for (int i=1;i<=p;i++)
            add_edge(i+r,n-1,pp[i]);
        for (int i=1;i<=mi;i++)
            add_edge(P[i].second.second,P[i].second.first+r,1000000);
        s=0; t=n-1;
        if (dinic() == sum) {
            ans=mi;
            hi=mi-1;
        } else
        lo=mi+1;
    }
    if (!ans) ans=-1; else
    ans=P[ans].first;
    cout<<ans<<endl;
}