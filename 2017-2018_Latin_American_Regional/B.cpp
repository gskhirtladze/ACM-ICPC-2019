#include <bits/stdc++.h>

using namespace std;

map < int , bool > f[100002][2];
map < int , int > dp[100002][2];
vector < int > a;
vector < int > c;

int solve(int l,int r,int rev) {
    if (l == r) return 1;
    if (f[l][rev][r]) {
        return dp[l][rev][r];
    }
    f[l][rev][r]=1;
    int su=c[r];
    int se=0;
    if (l) se=c[l-1];
    su-=se;
    if (a[l] == a[r] && a[l] == 1) {
        if (su) return 0;
        dp[l][rev][r]=1;
        return 1;
    }
    if (!rev) {
        if (!a[r]) {
            if (a[l]) return 0;
            dp[l][rev][r]=solve(l+1,r,rev^1);
            return dp[l][rev][r];
        }
        int x=1;
        while (a[r-x] == 1) x++;
        dp[l][rev][r]=solve(l,r-x,rev);
        if (a[l+1])
            dp[l][rev][r]+=solve(l+1,r,rev)*x;
        return dp[l][rev][r];
    }
    if (!a[l]) {
        if (a[r]) return 0;
        dp[l][rev][r]=solve(l,r-1,rev^1);
        return dp[l][rev][r];
    }
    int x=1;
    while (a[l+x] == 1) x++;
    dp[l][rev][r]=solve(l+x,r,rev); 
    if (a[r-1])
        dp[l][rev][r]+=solve(l,r-1,rev)*x;
    return dp[l][rev][r];
    
}

string s;

int main() {
    cin>>s;
    for (int i=0;i<s.size();i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
            a.push_back(0); else a.push_back(1);
    c.push_back(1-a[0]);
    for (int i=1;i<a.size();i++)
        c.push_back(c.back()+1-a[i]);
    cout<<solve(0,a.size()-1,0)<<endl;
}