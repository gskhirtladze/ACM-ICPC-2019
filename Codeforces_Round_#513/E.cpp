#include <bits/stdc++.h>

using namespace std;

vector < int > g[200020];
int all[200020][2];

void dfs(int p,int u) {
    for (int i=0;i<g[u].size();i++) {
        if (g[u][i] == p) continue;
        dfs(u,g[u][i]);
        all[u][0]+=all[g[u][i]][1];
        all[u][1]+=all[g[u][i]][0];
    }
    all[u][0]++;
}

long long res=0,rao=0;

void dfs2(int p,int u,int k,int l) {
    res+=1LL*k*all[u][1]+1LL*l*all[u][0];
    res+=1LL*k*all[u][0]+1LL*l*all[u][1];
    for (int i=0;i<g[u].size();i++) {
        if (g[u][i] == p) continue;
        int to=g[u][i];
        dfs2(u,to,all[u][0]-all[to][1]+l,all[u][1]-all[to][0]+k);
        rao+=1LL*all[to][1]*(all[u][1]-all[to][0]);
        rao+=1LL*all[to][0]*(all[u][0]-all[to][1]-1);
        rao+=2LL*all[to][0];
    }
}

int n,a,b,i;

int main() {
    cin>>n;
    for (i=1;i<n;i++) {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,1);
    dfs2(0,1,0,0);
    rao/=2;
    cout<<res<<" "<<rao<<endl;
    cout<<(res+rao)/2<<endl;
}