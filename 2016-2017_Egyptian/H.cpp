#include <bits/stdc++.h>

using namespace std;
int t,n,i,j,k,f,fl;
int ans[12][12][12];
int a[12][12][12];
int main() {
    freopen("commandos.in","r",stdin);
    cin>>t;
    while (t--) {
        for (i=0;i<=11;i++)
            for (j=0;j<=11;j++)
                for (k=0;k<=11;k++)
                    ans[i][j][k]=-1000000,a[i][j][k]=0;
        cin>>n;
        while (n--) {
            scanf("%d%d%d%d",&i,&j,&k,&f);
            a[i][j][k]+=f;
        }
        ans[10][1][1]=0;
        for (int fl=10;fl>=1;fl--)
            for (int i=1;i<=10;i++)
                for (int j=1;j<=10;j++) {
                    ans[fl][i][j]=max(ans[fl][i][j],a[fl][i][j]);
                    if (fl < 10)
                        ans[fl][i][j]=max(ans[fl][i][j],a[fl][i][j]+ans[fl+1][i][j]);
                    if (i > 1)
                        ans[fl][i][j]=max(ans[fl][i][j],a[fl][i][j]+ans[fl][i-1][j]);
                    if (j > 1)
                        ans[fl][i][j]=max(ans[fl][i][j],a[fl][i][j]+ans[fl][i][j-1]);
                }
        cout<<ans[1][10][10]<<endl;
    }
}