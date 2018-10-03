#include <bits/stdc++.h>

using namespace std;

vector < int > g[200020];
int P[200020];

void dfs(int p,int u) {
    P[u]=p;
    for (int i=0;i<g[u].size();i++) {
        if (g[u][i] == p) continue;
        dfs(u,g[u][i]);
    }
}

int t,n,a,b,c;
pair < int , pair < int , int > > no[200020];
int PP[200020];
int to[200020];
int f[200020];
int l,i,q;

int main() {
    cin>>t;
    while (t--) {
        scanf("%d%d",&n,&q);
        for (i=1;i<n;i++) {
            scanf("%d%d%d",&a,&b,&c);
            g[a].push_back(b);
            g[b].push_back(a);
            no[i].first=c;
            no[i].second={a,b};
        }
        dfs(0,1);
        for (i=1;i<=q;i++)
            scanf("%d",&PP[i]);
        for (i=1;i<=n;i++) f[i]=0,to[i]=0,g[i].clear();
        sort(PP+1,PP+q+1);
        sort(no+1,no+n);
        l=1;
        f[1]=1;
        int ans=1;
        long long pri=0;
        for (i=1;i<=q;i++) {
            while (l <= n-1 && no[l].first < PP[i]) {
                a=no[l].second.first;
                b=no[l].second.second;
                if (P[a] == b)
                    swap(a,b);
                to[a]=b;
                if (f[a]) {
                    while (ans!=a) {
                        f[ans]=0;
                        ans=P[ans];
                    }
                    while (to[ans] != 0) {
                        ans=to[ans];
                        f[ans]=1;
                    }
                }
                l++;
            }
            pri+=ans;
        }
        cout<<pri<<endl;
    }
}