#include <bits/stdc++.h>

using namespace std;

int n,k,i,j;
bool f[5005][5005];
int ans[5005];
int a[5005];

int main() {
    cin>>n>>k;
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (i=1;i<=n;i++) {
        int go=0,ba=0;
        for (j=i;j<=n;j++) {
            if (a[j] < k) go++; else ba++;
            if (ba > go)
             f[i][j]=1;
        }
    }
    for (i=1;i<=n;i++)
            ans[i]=-1000000000;
    for (i=1;i<=n;i++)
        for (j=0;j<i;j++)
            if (f[j+1][i])
                ans[i]=max(ans[i],ans[j]+1);
    if (ans[n]  < 0)
        ans[n]=0;
    cout<<ans[n]<<endl;
}