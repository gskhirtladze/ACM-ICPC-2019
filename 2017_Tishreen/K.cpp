#include <bits/stdc++.h>
#define P 1000000007
using namespace std;

int t,i,j;
int f[51][51];
int dp[51][51];
int st[51][51];

int solve(int l,int r) {
    if (f[l][r]) return dp[l][r];
    if (l >= r) {
        return 1;
    }
    f[l][r]=1;
    dp[l][r]=1;
    for (int jk=l;jk<r;jk++)
        for (int en=r;en>jk && st[en][r] <= st[l][jk];en--)
            if (st[en][r] == st[l][jk])
                dp[l][r]=(dp[l][r]+solve(jk+1,en-1))%P;
    return dp[l][r];
}

string s;

int main() {
    cin>>t;
    while (t--) {
        cin>>s;
        for (i=0;i<s.size();i++)
            for (j=0;j<s.size();j++)
                f[i][j]=0;
        
        for (i=0;i<s.size();i++) {
            st[i][i]=s[i]-'0';
            for (j=i+1;j<s.size();j++)
                st[i][j]=st[i][j-1]+s[j]-'0';
        }
        cout<<solve(0,s.size()-1)<<endl;
    }
}