#include <bits/stdc++.h>

using namespace std;

long long b[100020];
long long a[100020];
long long n;
long long m;

bool check(long long x) {
    long long now=0,in=0;
    for (long long i=1;i<=n+1;i++)
        b[i]=0;
    for (long long i=1;i<=n;i++)
        if (b[i] < x) {
            now+=i-in;
            in=i;
            long long rao=(x-b[i]+a[i]-1)/a[i];
            b[i]+=1LL*rao*a[i];
            b[i+1]+=1LL*(rao-1)*a[i+1];
            now+=2LL*(rao-1);
        }
    if (now <= m) return true;
    return false;
}

long long l,r,mi,ans;
long long t,i;

int main() {
    scanf("%lld",&t);
    while (t--) {
        scanf("%lld%lld",&n,&m);
        for (i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        l=1; r=1000000000000000000LL; ans=0;
        while (l <= r) {
            mi=(l+r)/2;
            if (check(mi)) {
                ans=mi;
                l=mi+1;
            } else r=mi-1;
        }
        printf("%lld\n",ans);
    }
}