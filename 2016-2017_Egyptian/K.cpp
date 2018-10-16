#include <bits/stdc++.h>

using namespace std;

double a[102][102];
double b[102][102];
int p[102];
double dp[102][102];
double tot,tot2,tot3;
int t,n,m,k,q,z,i,j,x;

int main() {
    freopen("trip.in","r",stdin);
    cin>>t;
    while (t--) {
        cin>>n>>m>>k>>q>>z;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                cin>>a[i][j];
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                cin>>b[i][j];
        for (i=0;i<k;i++)
            cin>>p[i];

        for (i=0;i<=k;i++)
            for (j=0;j<=n;j++)
                dp[i][j]=0;
        dp[0][0]=1;
        for (i=1;i<k;i++)
            for (j=0;j<n;j++)
                for (x=0;x<n;x++)
                    dp[i][j]+=dp[i-1][x]*a[x][j]*b[j][p[i]];
        tot=0;
        for (i=0;i<n;i++)
            tot+=dp[k-1][i];
        
        for (i=0;i<=k;i++)
            for (j=0;j<=n;j++)
                dp[i][j]=0;
        dp[0][0]=1;
        for (i=1;i<=q;i++)
            for (j=0;j<n;j++)
                for (x=0;x<n;x++)
                    dp[i][j]+=dp[i-1][x]*a[x][j]*b[j][p[i]];
        tot2=dp[q][z];

        for (i=0;i<=k;i++)
            for (j=0;j<=n;j++)
                dp[i][j]=0;
        dp[q][z]=1;
        for (i=q+1;i<k;i++)
            for (j=0;j<n;j++)
                for (x=0;x<n;x++)
                    dp[i][j]+=dp[i-1][x]*a[x][j]*b[j][p[i]];
        tot3=0;
        for (i=0;i<n;i++)
            tot3+=dp[k-1][i];
        
        printf("%.3f\n",tot3*tot2/tot);
    }
}