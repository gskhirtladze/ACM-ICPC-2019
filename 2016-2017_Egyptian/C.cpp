#include <bits/stdc++.h>

using namespace std;    

int link[2000];
bool used[2000];
vector<int> g[2000];
int n,m;
bool dfs(int u) {
	for (int i = 0; i<g[u].size(); i++) {
        int to=g[u][i];
		if (!used[to]) {
			used[to] = true;
			if (link[to] == -1 || dfs(link[to])) {
				link[to] = u;
				return true;
			}
		}
	}
	return false;
}
int hungary() {
	int u;
	int res = 0;
    for (int i=1;i<=m;i++)
        link[i]=-1;
	for (u = 1; u<=n; u++) {
        for (int i=1;i<=m;i++)
            used[i]=0;
		if (dfs(u)) res++;
	}
	return res;
}

double N,M,x,y;
int p,i,j,t;

 int main() {
     freopen("wall.in","r",stdin);
     cin>>t;
     while (t--) {
         cin>>N>>M>>p;
         n=N; m=M;
         for (int i=1;i<=n;i++)
            g[i].clear();
         for (i=1;i<=p;i++) {
             cin>>x>>y;
             for (j=1;j<=M;j++)
                if ( (N/2-x)*(N/2-x)+(j-y)*(j-y) <= N/2*N/2 ) {
                    y=j;
                    break;
                }
            for (j=1;j<=N;j++)
                if (j >= x) {
                    x=j;
                    break;
                }
            g[int(x)].push_back(int(y));
         }
         cout<<hungary()<<endl;
     }
 }