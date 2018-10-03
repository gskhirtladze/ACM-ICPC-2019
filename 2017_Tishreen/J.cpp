#include <bits/stdc++.h>

using namespace std;

long long a[2000];
long long b[2000];
long long r[2000];
int t,n,w,l,p[2000],fi[2000],se[2000],i;

int P(int u) {
    if (p[u] == u) return u;
    p[u]=P(p[u]);
    return p[u];
}

void uni(int u,int v) {
    u=P(u);
    v=P(v);
    if (u == v) return;
    p[u]=v;
}

int main() {
    cin>>t;
    while (t--) {
        scanf("%d%d%d",&n,&w,&l);
        for (i=1;i<=n;i++) {
            scanf("%lld%lld%lld",&a[i],&b[i],&r[i]);
            p[i]=i;
            fi[i]=0;
            se[i]=0;
        }
        for (i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if ((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]) <= (r[i]+r[j])*(r[i]+r[j]))
                    uni(i,j);
        for (i=1;i<=n;i++) {
            if (a[i] <= r[i])
                fi[P(i)]=1;
            if (a[i] >= w-r[i])
                se[P(i)]=1;
        }
        int ans=0;
        for (i=1;i<=n;i++)
            if (P(i) == i && se[i] && fi[i]) ans++;
        cout<<ans<<endl;
    }
}