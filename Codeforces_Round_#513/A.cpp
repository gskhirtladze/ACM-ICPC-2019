#include <bits/stdc++.h>

using namespace std;

int n,a,b,tot,i;
string s;

int main() {
    cin>>n;
    cin>>s;
    for (i=0;i<s.size();i++) {
        if (s[i] == '8') tot++;
    }
    a=tot;
    b=n-tot;
    for (i=100;i>=0;i--) {
        if (i <= a && 10*i <= (b+a-i)) {
            cout<<i<<endl;
            return 0;
        }
    }
}