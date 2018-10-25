#include <bits/stdc++.h>

using namespace std;

map < int , int > tot[35];
int res=2,n,y,x;

int main() {
    for (int t=0;t<2;t++) {
        cin>>n>>y;
        for (int i=1;i<=n;i++) {
            scanf("%d",&x);
            for (int j=1;j<=30;j++) {
                tot[j][(x+t*(1<<(j-1)))%(1<<j)]++;
                res=max(res,tot[j][(x+t*(1<<(j-1)))%(1<<j)]);
            }
        }
    }
    cout<<res<<endl;
}