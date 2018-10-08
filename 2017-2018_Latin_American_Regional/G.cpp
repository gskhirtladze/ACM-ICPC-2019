#include <bits/stdc++.h>

using namespace std;

long long is[100020][2][2];
int f[100020];
int g[100020][2];

void dfs(int u) {
    if (u == 0) {
        is[u][0][0]=1;
        is[u][1][1]=1;
        return;
    }
    int L=g[u][0];
    int R=g[u][1];
    dfs(L);
    dfs(R);
    for (int l=0;l<2;l++)
        for (int r=0;r<2;r++)
            for (int ll=0;ll<2;ll++)
                for (int rr=0;rr<2;rr++) {
                    int pos=!(l&r);
                    int rel=!(ll&rr);
                    if (f[u] != -1) rel=f[u];
                    is[u][pos][rel]+=is[L][l][ll]*is[R][r][rr];
                    is[u][pos][rel]%=1000000007;
                }
}

int n,a,b,c,i;

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        scanf("%d%d%d",&a,&b,&c);
        g[i][0]=a;
        g[i][1]=b;
        f[i]=c;
    }
    dfs(1);
    cout<<(is[1][0][1]+is[1][1][0])%1000000007<<endl;
}