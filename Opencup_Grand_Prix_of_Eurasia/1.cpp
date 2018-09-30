#include <bits/stdc++.h>

using namespace std;

int T,n,m,i,j,stx,sty;
int ans[150][150];
int a[150][150];
vector < pair < int , int > > x;
        
string s;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        cin>>s;
        stx=0; sty=0;
        x.clear();
        x.push_back({0,0});
        for (j=0;j<s.size();j++) {
            if (s[j] == 'D') stx++;
            if (s[j] == 'U') stx--;
            if (s[j] == 'L') sty--;
            if (s[j] == 'R') sty++;
            x.push_back({stx,sty});
        }
        
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        
        for (i=0;i<n;i++)
            for (j=0;j<m;j++) {
                ans[i][j]=0;
                for (int k=0;k<x.size();k++) {
                    stx=i+x[k].first;
                    sty=j+x[k].second;
                    if (stx < 0 || sty < 0 || stx >= n || sty >=m) {
                        ans[i][j]=0;
                        break;
                    }
                    ans[i][j]+=a[stx][sty];
                }
            }
        for (i=0;i<n;i++) {
            for (j=0;j<m;j++)
                printf("%d ",ans[i][j]);
            cout<<endl;
        }
    }
}