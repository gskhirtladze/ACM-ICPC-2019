#include <bits/stdc++.h>

using namespace std;

int n,h;
int a[200020];
int b[200020];
int sum[200020];
int sum2[200020];
int i,l,r,m,ans,res;

int main() {
    cin>>n>>h;
    for (i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]),
        sum[i]=sum[i-1]+a[i]-b[i-1],
        sum2[i]=sum2[i-1]+b[i]-a[i];
    for (i=n;i>=1;i--) {
        ans=i; l=i+1; r=n;
        while (l<=r) {
            m=(l+r)/2;
            if (sum[m]-sum[i] < h) {
                ans=m;
                l=m+1;
            } else r=m-1;
        }
        res=max(res,sum2[ans]-sum2[i-1]+h);
    }
    cout<<res<<endl;
}