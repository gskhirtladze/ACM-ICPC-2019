#include <bits/stdc++.h>

using namespace std;

long  long a[200020];
long long sum[200020];
long long l,r,k,m,lo,hi,mi,ans,ans2,res;
long long n,i;

int main() {
    cin>>n>>k;
    for (i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for (i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for (i=1;i<=n;i++) {
        l=0; r=k; int sav=0;
        while (l <= r) {
            m=(l+r)/2;
            lo=1; hi=i; ans=i;
            while (lo <= hi) {
                mi=(lo+hi)/2;
                if (a[mi]+m >= a[i]) {
                    ans=mi;
                    hi=mi-1;
                } else lo=mi+1;
            }
            lo=i; hi=n; ans2=i;
            while (lo <= hi) {
                mi=(lo+hi)/2;
                if (a[mi]-m <= a[i]) {
                    ans2=mi;
                    lo=mi+1;
                } else hi=mi-1;
            }
            if (sum[ans2]-sum[i]-(ans2-i)*a[i]-sum[i]+sum[ans-1]+(i-ans+1)*a[i] <= k) {
                sav=m;
                l=m+1;
            } else r=m-1;
        }
        lo=1; hi=i; ans=i; m=sav;
            while (lo <= hi) {
                mi=(lo+hi)/2;
                if (a[mi]+m >= a[i]) {
                    ans=mi;
                    hi=mi-1;
                } else lo=mi+1;
            }
            lo=i; hi=n; ans2=i;
            while (lo <= hi) {
                mi=(lo+hi)/2;
                if (a[mi]-m <= a[i]) {
                    ans2=mi;
                    lo=mi+1;
                } else hi=mi-1;
            }
        res=max(res, ans2-ans+1+(k-(sum[ans2]-sum[i]-(ans2-i)*a[i]-sum[i]+sum[ans-1]+(i-ans+1)*a[i]))/(sav+1));
    }
    cout<<min(n,res)<<endl;
}