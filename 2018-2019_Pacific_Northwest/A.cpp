#include <bits/stdc++.h>

using namespace std;

int n,k,tot,i;
string s,q;

int main() {
    cin>>k;
    cin>>s>>q; n=s.size();
    for (i=0;i<s.size();i++)
        if (s[i] == q[i]) tot++;
    cout<<min(k,tot)+min(n-k,n-tot)<<endl;
}