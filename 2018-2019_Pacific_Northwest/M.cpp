#include <bits/stdc++.h>

using namespace std;

double A,B,k,c[30002],h[30002],p[30002],CCC,res;
int i,j,n;
pair < double , int > pe[30002];

int main() {
    cin>>n>>CCC;
    for (i=1;i<=n;i++)
        cin>>c[i]>>h[i]>>p[i],
        res=max(res,(CCC/c[i])*h[i]*(CCC/c[i])*p[i]),
        pe[i].first=(-h[i]*p[i])/c[i],pe[i].second=i;
    sort(pe+1,pe+n+1);
    for (int ii=1;ii<=min(3000,n);ii++)
        for (int jj=ii+1;jj<=min(3000,n);jj++) {
            i=pe[ii].second; j=pe[jj].second;
            double A=h[i]-h[j]*c[i]/c[j];
            double B=p[i]-p[j]*c[i]/c[j];
            double C=h[j]*CCC/c[j];
            double D=p[j]*CCC/c[j];
            if (A == 0 || B == 0) continue;
            double x=-0.5*(D/B+C/A);
            if (x <= 0 | x*c[i] > CCC) continue;
            if (res < (x*A+C)*(x*B+D))
                res=(x*A+C)*(x*B+D);
        }
    printf("%.2f\n",res);
}

int lca(int a,int b) {
    if (in[a] <= in[b] && out[b] <= out[a]) return a;
    for (int i=17;i>=0;i--)
        if (P[a][i])
            if (!(in[P[a][i]] <= in[b] && out[b] <= out[P[a][i]]))
                a=P[a][i];
    return P[a][0];
}