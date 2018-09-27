#include<bits/stdc++.h>

using namespace std;

int n,k,i,j,l,r,m,res,ans,now;
int a[200020];

int main() {
    cin>>n>>k;
    for (i=1;i<=k;i++) {
        cin>>a[i];
    }
    l=1; r=n;
    while (l <= r) {
        m=(l+r)/2;
        res=0;
        for (i=1;i<=k;i++) {
            res+=a[i]/m;
        }
        if (res >= n) {
            ans=m;
            l=m+1;
        } else r=m-1;
    }
    cout<<ans<<endl;
    int m=n;
    for (i=1;i<=k;i++) {
        now=min(m,a[i]/ans);
        for (j=0;j<now;j++)
            cout<<i<<endl;
        m-=now;
    }
}