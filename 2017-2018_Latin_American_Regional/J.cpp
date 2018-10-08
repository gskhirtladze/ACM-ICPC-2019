#include <bits/stdc++.h>

using namespace std;

string s;
int n,i,ans;
bool can[200020];

void check(int x) {
    for (int i=0;i<x && !can[x];i++) {
        can[x]=true;
        for (int j=i;j<n;j+=x)
            if (s[j] != 'R') can[x]=false;
    }
}

int main() {
    cin>>s;
    n=s.size();
    for (i=1;i*i<=n;i++)
        if (n%i == 0) {
            check(i);
            check(n/i);
        }
    for (i=1;i<n;i++)
        if (can[__gcd(i,n)]) ans++;
    cout<<ans<<endl;
}