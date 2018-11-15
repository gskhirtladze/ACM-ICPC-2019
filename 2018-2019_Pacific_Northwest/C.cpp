#include <bits/stdc++.h>

using namespace std;

int a[200020];
map < int , int > tot;
int n,k,i,j;
long long ans[1001][1001];
long long res;

int main() {
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>a[i],tot[a[i]]++;
    sort(a+1,a+n+1);
    ans[0][0]=1;
    for (i=0;i<k;i++) {
        for (j=1;j<=n;j++)
            ans[i][j]+=ans[i][j-1];
        for (j=1;j<=n;j++)
            if (a[j] != a[j-1])
                ans[i+1][j]=(ans[i+1][j]+1LL*tot[a[j]]*ans[i][j-1])%998244353;
    }
    for (j=0;j<=n;j++)
        res=(res+ans[k][j])%998244353;
    cout<<res<<endl;
}