#include <bits/stdc++.h>

using namespace std;

int in[100020];
int out[100020];
int timer;
int P[100020][18];
int lvl[100020];
int indx[100020];
vector < int > g[100020];

void dfs(int p,int u) {
    P[u][0]=p;
    for (int i=1;i<=17;i++)
        P[u][i]=P[P[u][i-1]][i-1];
    timer++;
    in[u]=timer;
    indx[timer]=u;
    for (int i=0;i<g[u].size();i++)
        if (g[u][i] != p) {
            lvl[g[u][i]]=lvl[u]+1;
            dfs(u,g[u][i]);
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

pair < int , int > tr_mi[262144],tr_ma[262144];

void build(int t,int l,int r) {
    if (l == r) {
        tr_mi[t]={in[l],1000000};
        tr_ma[t]={in[l],0};
        return;
    }
    build(2*t,l,(l+r)/2);
    build(2*t+1,(l+r)/2+1,r);
    if (tr_mi[2*t] < tr_mi[2*t+1])
        tr_mi[t]={tr_mi[2*t].first,min(tr_mi[2*t].second,min(tr_mi[2*t+1].first,tr_mi[2*t+1].second))}; else
        tr_mi[t]={tr_mi[2*t+1].first,min(tr_mi[2*t+1].second,min(tr_mi[2*t].first,tr_mi[2*t].second))};
    if (tr_ma[2*t] > tr_ma[2*t+1])
        tr_ma[t]={tr_ma[2*t].first,max(tr_ma[2*t].second,max(tr_ma[2*t+1].first,tr_ma[2*t+1].second))}; else
        tr_ma[t]={tr_ma[2*t+1].first,max(tr_ma[2*t+1].second,max(tr_ma[2*t].first,tr_ma[2*t].second))};
}

pair < int , int > get_min(int t,int l,int r,int L,int R) {
    if (r < L || R < l) return {1000000,1000000};
    if (L <= l && r <= R) return tr_mi[t];
    pair < int , int > A=get_min(2*t,l,(l+r)/2,L,R);
    pair < int , int > B=get_min(2*t+1,(l+r)/2+1,r,L,R);
    if (A.first > B.first) swap(A,B);
    return {A.first,min(A.second,min(B.first,B.second))};
}

pair < int , int > get_max(int t,int l,int r,int L,int R) {
    if (r < L || R < l) return {0,0};
    if (L <= l && r <= R) return tr_ma[t];
    pair < int , int > A=get_max(2*t,l,(l+r)/2,L,R);
    pair < int , int > B=get_max(2*t+1,(l+r)/2+1,r,L,R);
    if (A.first < B.first) swap(A,B);
    return {A.first,max(A.second,max(B.first,B.second))};
}

int n,q,i,l,r;

int main() {
    cin>>n>>q;
    for (i=2;i<=n;i++) {
        int x;
        scanf("%d",&x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(0,1);
    build(1,1,n);
    while (q--) {
        scanf("%d %d",&l,&r);
        pair < int , int > A=get_min(1,1,n,l,r);
        pair < int , int > B=get_max(1,1,n,l,r);
        int mi1=indx[A.first];
        int mi2=indx[A.second];
        int ma1=indx[B.first];
        int ma2=indx[B.second];
        int k1=lca(mi1,ma2);
        int k2=lca(mi2,ma1);
        if (lvl[k1] > lvl[k2])
            printf("%d %d\n",ma1,lvl[k1]); else
            printf("%d %d\n",mi1,lvl[k2]);
    }
}