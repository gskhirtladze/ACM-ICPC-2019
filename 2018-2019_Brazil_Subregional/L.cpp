#include <bits/stdc++.h>

using namespace std;

int in[200020];
int out[200020];
int timer;
int lvl[200020];
int P[200020][18];
vector < int > g[200020];

void dfs(int p,int u) {
    in[u]=++timer;
   
    lvl[u]=lvl[p]+1;
    P[u][0]=p;
    for (int i=1;i<=17;i++)
        P[u][i]=P[P[u][i-1]][i-1];
    for (int i=0;i<g[u].size();i++)
        if (g[u][i] != p)
            dfs(u,g[u][i]);
    
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

int goUp(int a,int x) {
    for (int i=17;i>=0;i--)
        if ((1<<i) <= x) {
            a=P[a][i];
            x-=(1<<i);
        }
    return a;
}

bool up(int A,int B) {
    return (in[A] <= in[B] && out[B] <= out[A]);
}

int solve(int A,int B,int C,int D) {
    if (!(up(B,D))) { swap(A,C); swap(B,D); }
    if (!up(B,D)) return 0;
    if (!up(D,A)) return 0;
    return lvl[lca(A,C)]-lvl[D]+1;
}

int n,q,i,x,y,A,B,C,D;

int main() {
    cin>>n>>q;
    for (i=1;i<n;i++) {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0,1);
    while (q--) {
        scanf("%d%d%d%d",&A,&B,&C,&D);
        int k=lca(A,B);
        int j=lca(C,D);
        if (k == A) swap(A,B);
        if (j == C) swap(C,D);
        int E=goUp(A,lvl[A]-lvl[k]-1);
        int F=goUp(C,lvl[C]-lvl[j]-1);
        int ans=0;
        ans+=solve(A,E,C,F);
        if (C != D)
            ans+=solve(A,E,D,j);
        if (A != B) {
            ans+=solve(B,k,C,F);
            if (C != D)
                ans+=solve(B,k,D,j);
        }
        cout<<ans<<endl;
    }
}