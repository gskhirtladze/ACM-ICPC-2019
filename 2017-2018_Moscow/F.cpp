#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,r,c;
bool f[2002][2002];
char a[2002][2002];

int main() {
    cin>>n; m=n;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            cin>>a[i][j];
    cin>>r>>c;
    while (!f[r][c]) {
        f[r][c]=1;
        if (a[r][c] == '.') continue;
        if (!('A' <= a[r][c] && a[r][c] <= 'Z')) continue;
        if (a[r][c] == 'N') r--; else
        if (a[r][c] == 'E') c++; else
        if (a[r][c] == 'S') r++; else
        if (a[r][c] == 'W') c--;
    }
    if (a[r][c] == '.') {
        cout<<r<<" "<<c<<endl;
        return 0;
    }
    if (!('A' <= a[r][c] && a[r][c] <= 'Z')) {
        cout<<0<<endl;
        return 0;
    }
    cout<<-1<<endl;
}