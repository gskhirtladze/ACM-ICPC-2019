#include <bits/stdc++.h>

using namespace std;

int n,k,i,j;
int a[200020];
int totz[200020];
int tot[200020][102];
int sum[200020][102];
long long ans[102];
long long nxt[102];
long long res;

int main() {
    cin>>n>>k;
    for (i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        for (j=1;j<=k;j++)
            sum[i][j]=sum[i-1][j];
        if (a[i] == 0)
            continue;
        for (j=a[i];j<=k;j++)
            sum[i][j]++;
        res+=sum[i][k]-sum[i][a[i]];
    }
    for (i=n;i>=1;i--) {
        totz[i]=totz[i+1];
        if (!a[i])
            totz[i]++;
    }
    for (i=1;i<=n;i++) {
        if (a[i]) continue;
        for (j=1;j<=k;j++)
            tot[i][j]=sum[n][j-1]-sum[i][j-1]+sum[i][k]-sum[i][j];
    }
    for (j=0;j<=k+1;j++)
        ans[j]=res;
    for (i=1;i<=n;i++) { 
        if (a[i]) continue;
        for (j=0;j<=k;j++)
            nxt[j]=max(ans[j]-1,ans[j+1])+totz[i+1]+tot[i][j];
        for (j=k+1;j>=1;j--)
            ans[j]=max(ans[j+1],nxt[j]);
    }
    cout<<ans[1]<<endl;
}