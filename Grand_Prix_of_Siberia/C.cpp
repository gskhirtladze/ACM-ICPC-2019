#include <bits/stdc++.h>

using namespace std;

int n,i,j,g[2002][2002];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            scanf("%d",&g[i][j]);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            g[n][i]=g[i][n]=min(g[n][i],g[n][j]+g[i][j]);
    
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            g[i][j]=min(g[i][j],g[i][n]+g[n][j]);
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++)
            printf("%d ",g[i][j]);
        printf("\n");
    }
}