#include <bits/stdc++.h>

using namespace std;

#define MX 1000000000000000001

long long dp[5002][12][12];
int fr[5002][12][12];
int pr[5002][12];
vector < int > sent[5002];
bool can[5002][1002];
string text;
int n,m,k,i,j,si;
int x,num;
string s[5002];
vector < string > res;

int main() {
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for (i=1;i<=n;i++) {
        cin>>s[i]>>num;
        while (num--) {
            cin>>x;
            pr[i][x]=1;
        }
    }
    for (i=1;i<=m;i++) {
        cin>>num;
        while (num--) {
            cin>>x;
            sent[i].push_back(x);
        }
    }
    cin>>text;
    for (i=1;i<=n;i++)
        for (j=0;j<text.size();j++) {
            if (j+s[i].size()-1 >= text.size()) continue;
            for (k=0;k<s[i].size();k++)
                if (text[j+k] != s[i][k]) break;
            if (k != s[i].size()) continue;
            can[i][j]=true;
        }
    dp[0][0][0]=1;
    for (i=0;i<=text.size();i++) {
        for (j=1;j<=m;j++) {
            dp[i][0][0]+=dp[i][j][sent[j].size()-1];
            if (dp[i][0][0] > MX) dp[i][0][0]=MX;
            if (dp[i][j][sent[j].size()-1] > 0)
                fr[i][0][0]=-j;
        }
        for (j=1;j<=m;j++)
            for (si=1;si<=n;si++)
                if (can[si][i] && pr[si][sent[j][0]]) {
                    dp[i+s[si].size()][j][0]+=dp[i][0][0];
                    if (dp[i+s[si].size()][j][0] > MX)
                        dp[i+s[si].size()][j][0]=MX;
                    if (dp[i][0][0] > 0)
                        fr[i+s[si].size()][j][0]=si;
                }
        for (si=1;si<=n;si++)
            if (can[si][i])
                for (j=1;j<=m;j++)
                    for (k=0;k+1<sent[j].size();k++)
                        if (pr[si][sent[j][k+1]]) {
                            dp[i+s[si].size()][j][k+1]+=dp[i][j][k];
                            if (dp[i+s[si].size()][j][k+1] > MX)
                                dp[i+s[si].size()][j][k+1]=MX;
                            if (dp[i][j][k] > 0)
                                fr[i+s[si].size()][j][k+1]=si;
                        }
    }
        if (dp[text.size()][0][0] == MX) {
            cout<<"TOO MANY"<<endl;
        } else {
            cout<<dp[text.size()][0][0]<<endl;
        }

        if (dp[text.size()][0][0] != 0) {
            int A=text.size();
            int B=0,C=0;
            while (A > 0) {
                int tmp=fr[A][B][C];
                if (tmp < 0) {
                    res.push_back(".");
                    B=-tmp;
                    C=sent[B].size()-1;
                } else {
                    A-=s[tmp].size();
                    C--;
                    if (C < 0) { C=B=0; }
                    if (!A) {
                        res.push_back(s[tmp]);
                    } else
                    res.push_back(string(" "+s[tmp]));
                }
            }
            
    reverse(res.begin(),res.end());
    for (i=0;i<res.size();i++)
        cout<<res[i];
    cout<<endl;
        }
}