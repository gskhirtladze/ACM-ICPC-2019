#include <bits/stdc++.h>

using namespace std;

int to(string x) {
    if (x == "red") return 1;
    if (x == "yellow") return 2;
    if (x == "green") return 3;
    if (x == "brown") return 4;
    if (x == "blue") return 5;
    if (x == "pink") return 6;
    return 7;
}

int f[8];
int res,n,i;
string s;
int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>s;
        f[to(s)]++;
    }
    res=f[1]+2*f[2]+3*f[3]+4*f[4]+5*f[5]+6*f[6]+7*f[7];
    int x=7;
    while (!f[x]) x--;
    if (x > 1) res+=f[1]*x; else res=1;
    cout<<res<<endl;
}