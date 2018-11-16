#include <bits/stdc++.h>

using namespace std;

long long n,k,i,fib[101],m,tot;
map < long long , bool > f;

void solve(int l,int r,int sum) {
    if (l == m) {
        tot++;
        f[sum]=1;
        return;
    }
    for (int i=r;i<=n;i++)
        solve(l+1,i,sum+fib[i]);
}

int main() {
    fib[1]=1;
    fib[2]=2;
    for (i=3;;i++) {
        fib[i]=fib[i-1]+fib[i-2];
        if (fib[i] > 1000000000000000000) break;
    }
    n=25;
    cin>>m;
    solve(0,1,0);
    for (i=1;i<=10000000;i++)
        if (!f[i]) cout<<i<<" ";
    cout<<tot<<endl;
}