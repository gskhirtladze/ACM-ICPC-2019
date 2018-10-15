#include <bits/stdc++.h>

using namespace std;

char now[100020];
string arr,s;
int t,timer;
int in[100020];
int out[100020];
int P[100020][18];
set < int > st[100020];
set < int > st_rev[100020];
int no[100020];
int no_rev[100020];
int lvl[100020];
int ind[100020];
vector < int > g[100020];

void dfs(int p,int u) {
    now[++t]=arr[u];
    in[u]=++timer;
    for (int i=0;i<s.size();i++) {
        if (t-i <= 0 || s[i] != now[t-i])
            st[u].insert(i);
    }
    for (int i=0;i<s.size();i++) {
        if (t-i <= 0 || s[s.size()-i-1] != now[t-i])
            st_rev[u].insert(i);
    }
    no[u]=(st[u].size() == 0);
    no_rev[u]=(st_rev[u].size() == 0);
    ind[in[u]]=u;

    lvl[u]=lvl[p]+1;
    P[u][0]=p;
    for (int i=1;i<=17;i++)
        P[u][i]=P[P[u][i-1]][i-1];
    for (int i=0;i<g[u].size();i++)
        if (g[u][i] != p)
            dfs(u,g[u][i]);
    --t;
    out[u]=timer;
}

int lca(int a,int b) {
    if (in[a] <= in[b] && out[b] <= out[a]) return a;
    for (int i=17;i>=0;i--)
        if (P[a][i])
            if (!(in[P[a][i]] <= in[b] && out[b] <= out[P[a][i]]))
                a=P[a][i];
    return a;
}

int goUp(int a,int x) {
    for (int i=17;i>=0;i--)
        if ((1<<i) <= x) {
            a=P[a][i];
            x-=(1<<i);
        }
    return a;
}

int tr[262144];
int tr_rev[262144];

void build (int t,int l,int r) {
    if (l == r) {
        tr[t]=no[ind[l]];
        tr_rev[t]=no_rev[ind[l]];
        return;
    }
    build(2*t,l,(l+r)/2);
    build(2*t+1,(l+r)/2+1,r);
}

void add(int t,int l,int r,int L,int R,int a,int b) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
        tr[t]+=a;
        tr_rev[t]+=b;
        return;
    }
    add(2*t,l,(l+r)/2,L,R,a,b);
    add(2*t+1,(l+r)/2+1,r,L,R,a,b);
}

int A,B;

void get(int t,int l,int r,int x) {
    if (x < l || r < x) return;
    A+=tr[t];
    B+=tr_rev[t];
    if (l == r) return;
    get(2*t,l,(l+r)/2,x);
    get(2*t+1,(l+r)/2+1,r,x);
}

int n,q,x,y,ans;

int main() {
    cin>>n>>q;
    cin>>s;
    cin>>arr;
    for (int i=1;i<n;i++) {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0,1);
    build(1,1,n);
    while (q--) {
        int c;
        scanf("%d",&c);
        if (c == 1) {
            scanf("%d%d",&x,&y);
            ans=0;
            int k=lca(x,y);

            int dif1=lvl[x]-lvl[k]-s.size();
            
            A=B=0;
            get(1,1,n,in[x]);
            ans+=A;
            
            A=B=0;
            get(1,1,n,in[goUp(x,dif1+1)]);
            ans-=A;

            int dif2=lvl[y]-lvl[k]-s.size();
            
            A=B=0;
            get(1,1,n,in[y]);
            ans+=B;
            
            A=B=0;
            get(1,1,n,in[goUp(y,dif2+1)]);
            ans-=B;
            
            cout<<ans<<endl;
        } else {
            char ch;
            scanf("%d %c",)
        }
    }
}
