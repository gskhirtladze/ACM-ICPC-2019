#include <bits/stdc++.h>

using namespace std;

long long dst[3][100020];
unsigned long long ans[3][100020];
bool f[100020];
priority_queue < pair < long long , int > > q;
int n;
vector < pair < int , int > > g[100020];

void diji(int st) {
    ans[st][st]=1;
    for (int i=1;i<=n;i++)
        dst[st][i]=1000000000000000LL,f[i]=0;
    dst[st][st]=0;
    q.push({0,st});
    while (q.size()) {
        int u=q.top().second;
        q.pop();
        if (f[u]) continue;
        f[u]=1;
        for (int i=0;i<g[u].size();i++) {
            if (dst[st][g[u][i].first] > dst[st][u]+g[u][i].second) {
                q.push({-dst[st][u]-g[u][i].second,g[u][i].first});
                dst[st][g[u][i].first]=dst[st][u]+g[u][i].second;
                ans[st][g[u][i].first]=0;
            }
            if (dst[st][g[u][i].first] == dst[st][u]+g[u][i].second)
                ans[st][g[u][i].first]+=ans[st][u];
        }
    }
}

vector < pair < int , int > > gr[100020];
int m,i;
int a[100020],b[100020],c[100020];

int main() {
    cin>>n>>m;
    for (i=1;i<=m;i++) {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        g[a[i]].push_back({b[i],c[i]});
        gr[b[i]].push_back({a[i],c[i]});
    }
    diji(1);
    for (i=1;i<=n;i++)
        swap(g[i],gr[i]);
    diji(2);
    for (i=1;i<=m;i++) {
        if (dst[1][2] > dst[1][b[i]]+c[i]+dst[2][a[i]]) {
            printf("HAPPY\n");
            continue;
        }
        if (dst[1][a[i]]+dst[2][b[i]]+c[i] > dst[1][2]) {
            printf("SOSO\n");
            continue;
        }
        if (ans[1][a[i]]*ans[2][b[i]] == ans[1][2]) {
            printf("SAD\n");
            continue;
        }
        printf("SOSO\n");
    }
}