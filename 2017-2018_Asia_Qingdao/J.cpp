#include <bits/stdc++.h>

using namespace std;

int k,a[200020];
int t,n,l,r,m;
long long ans;

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&m,&k);
        ans=0; n=0;
        for (int i=1;i<=m;i++) {
            scanf("%d",&l);
            if (l == 0) k--; else {
                a[++n]=l;
            }
        }
        if (k < 0) {
            printf("Impossible\n");
            continue;
        }
        if (k == n) {
            printf("Richman\n");
            continue;
        }
        for (int i=1;i<=k;i++)
            ans+=a[i];
        r=a[k+1];
        for (int i=k+1;i<=n;i++)
            r=min(r,a[i]);
        ans+=r-1;
        printf("%lld\n",ans);
    }
}