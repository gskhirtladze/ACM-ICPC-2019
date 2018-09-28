#include <bits/stdc++.h>

#define SQ 270

using namespace std;

vector < pair < int , int > > all[300];
int ans[200020];
int n,q,st,x,d;
int i,j;

int main() {
    cin>>n>>q;
    for (i=1;i<=q;i++) {
        cin>>st>>x>>d;
        if (d > SQ) {
            for (j=st;j<=n;j+=d)
                ans[j]++;
            continue;
        }
        all[d].push_back({st,x});
    }
    for (d=1;d<=SQ;d++) {
        vector < int > res[d];
        for (i=0;i<=n;i++)
            res[i%d].push_back(0);
        for (i=0;i<all[d].size();i++) {
            int row=all[d][i].first%d;
            int l=all[d][i].first/d;
            int r=all[d][i].second+l-1;
            res[row][l]++;
            if (r+1 < res[row].size())
                res[row][r+1]--;
        }
        for (i=0;i<d;i++) {
            if (res[i].size() == 0) continue;
            ans[i]+=res[i][0];
            for (j=1;j<res[i].size();j++) {
                res[i][j]+=res[i][j-1];
                ans[i+j*d]+=res[i][j];
            }
        }
    }
    for (i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}