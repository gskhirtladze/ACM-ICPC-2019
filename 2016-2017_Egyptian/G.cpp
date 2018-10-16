#include <bits/stdc++.h>

using namespace std;

int N,K,t,i,j;
long long ans[1005][1005];

int main() {
    freopen("galactic.in","r",stdin);
    ans[1][1]=1;
    for (i=2;i<=1000;i++) {
        ans[i][1]=1;
        for (j=2;j<=i;j++)
            ans[i][j]=(1LL*j*(ans[i-1][j-1]+ans[i-1][j]))%1000000007;
    }
    cin>>t;
    while (t--) {
        scanf("%d%d",&N,&K);
        if (K > N) {
            cout<<0<<endl;
            continue;
        }
        cout<<ans[N][K]<<endl;
    }
}