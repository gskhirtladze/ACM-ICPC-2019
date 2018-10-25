#include <bits/stdc++.h>

using namespace std;

int n,m;
int s[102],h[102],a[102],b[102],f[102];
int st,i,j;

int main() {
    cin>>n>>m;
    for (i=1;i<=m;i++)
        cin>>s[i]>>h[i];
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (st=1;st<=n;st++) {
        vector < int > now;
        for (i=1;i<=n;i++)
            b[i]=a[i],f[i]=0;
        for (j=1;j<=m;j++) {
            for (i=1;i<=m;i++)
                if (!f[i]) {
                int x=s[i],y=h[i];
                while (x != st) {
                    if (x < st)
                        x++; else x--;
                    y+=b[x];
                    if (y < 0) break;
                }
                if (y < 0)
                    continue;
                x=s[i]; y=h[i];
                while (x != st) {
                    if (x < st)
                        x++; else x--;
                    y+=b[x]; b[x]=0;
                }
                now.push_back(i); f[i]=1;
                break;
            }
        }
        if (now.size() == m) {
            cout<<st<<endl;
            for (i=0;i<m;i++)
                cout<<now[i]<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}