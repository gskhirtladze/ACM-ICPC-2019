#include <bits/stdc++.h>

using namespace std;

set < pair < int , int > > s;
int x,a[2002],b[2002],f[2002];
vector < int > ans[2002];
int i,n,m;
int main() {
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    cin>>m;
    for (i=1;i<=m;i++) {
        cin>>x;
        s.insert({x,i});
    }
    while (s.size() > 0) {
        int ned=(*s.rbegin()).first;
        int id=(*s.rbegin()).second;
        s.erase(*s.rbegin());
        int mx=-1,ii=-1;
        for (int i=1;i<=n;i++)
            if (!f[i] && b[i] >= ned) {
                if (ii == -1 || mx > a[i]) {
                    mx=a[i];
                    ii=i;
                }
            }
        if (ii == -1) {
            cout<<"impossible"<<endl;
            return 0;
        }
        ans[id].push_back(ii);
        f[ii]=1;
        ned=mx;
        if (ned)
            s.insert({ned,id});
    }
    for (int i=1;i<=m;i++) {
        reverse(ans[i].begin(),ans[i].end());
        for (int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}