#include <bits/stdc++.h>

using namespace std;

double a[11],v[11];
double x[11],d[11];
double h[11],ans[11];
double HH[11],VV[11];
double now[11];
int st2[11],en2[11],st[11],en[11];
double q,s,sav;
int n,m,i,j,l,r,mi;

int main() {
    cin>>n>>m>>s;
    for (i=1;i<=n;i++)
        cin>>v[i]>>a[i];
    for (i=1;i<=m;i++)
        cin>>x[i]>>d[i];
    cin>>q;
    for (i=1;i<=m;i++)
        for (j=i+1;j<=m;j++)
            if (x[i] > x[j]) {
                swap(x[i],x[j]);
                swap(d[i],d[j]);
            }
    double delta = 0.000000001;

    while (true) {
        int fi=0;
        
        for (i=1;i<=n;i++) {
            if (v[i] < 0.00000001) v[i]=0;
            now[i]=0;
        }

        for (fi=1;fi<=n;fi++)
            if (v[fi] >= 0.00000001) break;

        if (fi == n+1) break;

        for (i=1;i<=n;i++) 
            h[i]=h[i-1]+v[i]/s;
        j=1;
        for (i=1;i<=n;i++)
            {
                    while (j <= m && x[j] <= h[i-1]) j++;
                    st[i]=j;
                    while (j <= m && x[j] <= h[i])  {
                        now[i]+=a[i]*d[j]; j++;
                    }
                    en[i]=j;
            }
        
        now[fi]+=a[fi]*q;
        sav=0;
        l=1; r=1000000;
        while (l <= r) {
            mi=(l+r)/2;
            
            for (i=1;i<=n;i++) {
                VV[i]=v[i]-now[i]*mi*delta;
                if (VV[i] < 0) break;
            }
            if (i != n+1) {
                r=mi-1;
                continue;
            }
            for (i=1;i<=n;i++) 
                HH[i]=HH[i-1]+VV[i]/s;
            j=1;
            for (i=1;i<=n;i++) {
                    while (j <= m && x[j] <= HH[i-1]) j++;
                    st2[i]=j;
                    while (j <= m && x[j] <= HH[i])
                        j++;
                    en2[i]=j;
            }
            for (i=1;i<=n;i++)
                if (st[i] != st2[i] || en[i] != en2[i]) break;
            if (i != n+1) {
                r=mi-1;
                continue;
            }
            sav=mi;
            l=mi+1;
        }
        sav++;
        ans[fi]+=a[fi]*q*sav*delta;
        for (i=1;i<=n;i++)
            v[i]=v[i]-now[i]*sav*delta; 
    }
    for (i=1;i<=n;i++)
        printf("%.11f\n",ans[i]);
}