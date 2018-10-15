#include <bits/stdc++.h>

using namespace std;

int f[102][102];
int d[102][102];

int solve(int x,int y) {
    if (f[x][y]) return d[x][y];
    f[x][y]=1;
    vector < int > all;
    for (int i=1;i<y;i++)
    if (y-i != x)
        all.push_back(solve(x,y-i));
    for (int i=1;i<x;i++)
        if (x-i != y)
        all.push_back(solve(x-i,y));
    for (int i=1;i<min(x,y);i++)
        all.push_back(solve(x-i,y-i));
    sort(all.begin(),all.end());
    if (all.size() == 0) return 0;
    if (all[0] != 0) return 0;
    for (int i=1;i<all.size();i++)
        if (all[i-1]+1 < all[i]) {
            d[x][y]=all[i-1]+1;
            return d[x][y];
        }
    d[x][y]=all.back()+1;
    return d[x][y];
}
int n,x,y,i,all;
int a[100020];
int main() {
    for (int i=0;i<=100;i++)
        for (int j=0;j<=100;j++)
            solve(i,j);
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x>>y;
        if (x == y) {
            cout<<"Y"<<endl;
            return 0;
        }
        all^=solve(x,y);
    }
    
    if (all)
        cout<<"Y"<<endl; else
        cout<<"N"<<endl;
}