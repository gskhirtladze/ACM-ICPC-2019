#include <bits/stdc++.h>

using namespace std;

int T;
int n,m,s;
int a[200020];
int ra[200020];
int c[200020];
int i,x;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    while (T--) {
        cin>>n>>m>>s;
        for (i=1;i<=n;i++)
            a[i]=0;
        for (i=1;i<=m;i++) {
            scanf("%d",&x);
            a[x]++;
        }
        for (i=1;i<=n;i++)
            scanf("%d%d",&ra[i],&c[i]);
        double l=0,r=1000000000+20000000;
        for (int it=0;it<70;it++) {
            double mi=(l+r)/2;
            double now=0;
            for (i=1;i<=n;i++) {
                double need=mi*a[i];
                double b=need-ra[i];
                if (b < 0)
                    continue;
                now+=b*c[i];
            }
            if (now <= s)
                l=mi; else r=mi;
        }
        printf("%.11f\n",l);
    }
}