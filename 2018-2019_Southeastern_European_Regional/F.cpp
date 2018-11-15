#include <bits/stdc++.h>

using namespace std;

bool f[200020];
int a[200020];
int b[200020];
int sav[200020];
int n;

void solve(int u) {
    if (f[u]) return;
    f[u]=1;
    if (u+1 <= n && sav[u+1] <= u)
        solve(u+1);
    if (sav[u] == u) {
        printf("m %d %d\n",u,u);
        printf("M %d %d\n",u,u);
        return;
    }
    if (sav[u] < u) {
        char ch;
        if (a[sav[u]+1] > a[sav[u]])
            ch='M'; else ch='m';
        printf("%c %d %d\n",ch,sav[u]+1,u);
        printf("%c %d %d\n",'M'+'m'-ch,sav[u],u); 
        return;
    }
    if (sav[u] > u) {
        char ch;
        if (a[sav[u]-1] > a[sav[u]])
            ch='M'; else ch='m';
        printf("%c %d %d\n",ch,u,sav[u]-1);
        printf("%c %d %d\n",'M'+'m'-ch,u,sav[u]);
        return;
    }
}

int i,j,st;

int main() {
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (j=1;j<=n;j++)
        cin>>b[j];
    st=1;
    for (i=1;i<=n;i++) {
        while (st <= n && a[st] != b[i]) st++;
        if (st == n+1) break;
        sav[i]=st;
    }
    if (st > n) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<2*n<<endl;
    for (i=1;i<=n;i++)
        solve(i);
}