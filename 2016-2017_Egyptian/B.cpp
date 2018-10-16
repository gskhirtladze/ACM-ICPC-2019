#include <bits/stdc++.h>

#define H first.first
#define W first.second
#define D second.first
#define x second.second

using namespace std;

double dst[105][105];
pair < pair < double , double > , pair < double , double > > P[105];
int n,t,L,U,i,j;

int main() {
    freopen("street.in","r",stdin);
    cin>>t;
    while (t--)  {
        scanf("%d%d%d",&n,&L,&U);
        for (i=1;i<=n;i++) {
            cin>>P[i].H>>P[i].W>>P[i].D>>P[i].x;
            dst[0][i]=P[i].D;
            dst[i][n+1]=L-P[i].D-P[i].H;
        }
        dst[0][n+1]=1000000000;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++) {
                if (i == j) continue;
                if (P[i].x != P[j].x) {
                    if (P[i].D <= P[j].D && P[j].D <= P[i].D+P[i].H || P[j].D <= P[i].D && P[i].D <= P[j].D+P[j].H)
                        dst[i][j]=U-P[i].W-P[j].W; else
                    if (P[i].W+P[j].W >= U)
                         dst[i][j]=min(abs(P[j].D-P[i].D-P[i].H),abs(P[i].D-P[j].D-P[j].H)); else {
                        
                        dst[i][j]=1.0*sqrt(1.0*(U-P[i].W-P[j].W)*(U-P[i].W-P[j].W)+1.0*min(abs(P[j].D-P[i].D-P[i].H),abs(P[i].D-P[j].D-P[j].H))*min(abs(P[j].D-P[i].D-P[i].H),abs(P[i].D-P[j].D-P[j].H))); 
                         }
                    } else
                dst[i][j]=min(abs(P[j].D-P[i].D-P[i].H),abs(P[i].D-P[j].D-P[j].H));
                }
        for (int k=0; k<=n+1; ++k)
            for (int i=0; i<=n+1; ++i)
                for (int j=0; j<=n+1; ++j)
                        dst[i][j] = min (dst[i][j], dst[i][k] + dst[k][j]);
        printf("%.6f\n",dst[0][n+1]);
    }
}