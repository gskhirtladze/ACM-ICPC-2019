#include <bits/stdc++.h>

#define en first
#define cs second.first
#define id second.second

using namespace std;

vector < pair < int , pair < int , int > >  > st[86402];
int n,m,a,b,c,i;
int f[86402][1024];

int main() {
    cin>>n;
    for (i=0;i<n;i++) {
        cin>>m;
        for (int j=1;j<=m;j++) {
            cin>>a>>b>>c;
            st[a].push_back({b,{c,i}});
        }
    }
    for (int i=0;i<=86400;i++) 
        for (int j=0;j<(1<<n)-1;j++)
            f[i][j]=-2000000000;
    f[0][0]=0;
    for (int i=1;i<=86400;i++) 
        for (int j=0;j<(1<<n)-1;j++) {
            f[i][j]=max(f[i][j],f[i-1][j]);
            for (int k=0;k<st[i].size();k++) {
                f[st[i][k].en][j|(1<<st[i][k].id)]=max(f[st[i][k].en][j|(1<<st[i][k].id)],f[i][j]+st[i][k].cs);
            }
    }
    int ans=f[86400][(1<<n)-1];
    cout<<ans<<endl;
    if (ans <= 0) ans=-1;
    cout<<ans<<endl;
}