#include <bits/stdc++.h>

using namespace std;

#define MAXN 300020
#define INF 1000000000

struct edge {
	int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector <edge> e;
vector <int> g[MAXN];
bool f[MAXN];
string str[MAXN];
int need;
int ans[MAXN];
pair < int , int > cur[MAXN];
 
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
            if (e[id].flow != 0)
                if (e[id].b >= 1 && e[id].b <= need)
                    ans[cur[e[id].a].first]=cur[e[id].a].second;
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

string tostr(int x) {
    string ret="";
    while (x)
        ret+=char(x%10+'0'),
        x/=10;
    reverse(ret.begin(),ret.end());
    return ret;
}

int all,m,i,j,x,y;
string name,now;
vector < int > pr[MAXN];
map < string , int > mp;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    need = n;
    str[0]="start";
    str[n+1]="end";
    all=n+2;
    for (i=1;i<=n;i++) {
        str[i]=tostr(i);
        cin>>name;
        add_edge(i,n+1,1);
        scanf("%d",&x);
        while (x--) {
            scanf("%d",&y);
            now=name+tostr(y);
            ++all;
            pr[i].push_back(all);
            mp[now]=all;
            str[all]=now;
            cur[all]={i,y};
            add_edge(all,i,1);
        }
    }
    cin>>m;
    while (m--) {
        all++;
        str[all]="M";
        add_edge(0,all,1);
        cin>>x;
        while (x--) {
            cin>>name; scanf("%d",&y);
            now=name+tostr(y);
            y=mp[now];
            f[y]=1;
            add_edge(all,y,1);
        }
    }
    for (i=1;i<=n;i++)
        for (j=0;j<pr[i].size();j++)
            if (!f[pr[i][j]])
                add_edge(0,pr[i][j],1);
    s = 0;
    t = n+1;
    n = all+1;
    
    if (dinic() != need) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for (i=1;i<=need;i++)
        printf("%d ",ans[i]);
    cout<<endl;
}