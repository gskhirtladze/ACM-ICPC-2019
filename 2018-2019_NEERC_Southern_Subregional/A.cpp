#include <bits/stdc++.h>

using namespace std;

int ans[500][5005];
int fr1[500][5005];
int fr2[500][5005];
vector < pair < int , int > > step,nxt;
string res;
int d,n;

int main() {
    cin>>d>>n;
    ans[0][0]=1;
    step.push_back({0,0});
    for (;step.size();) {
        if (!step.size()) continue;
        for (int l=0;l<step.size();l++) {
            int now=step[l].first;
            int sum=step[l].second;
            for (int i=0;i<=9;i++)
                if (sum+i <= n && !ans[(now*10+i)%d][sum+i]) {
                    ans[(now*10+i)%d][sum+i]=1;
                    fr1[(now*10+i)%d][sum+i]=now;
                    fr2[(now*10+i)%d][sum+i]=i;
                    nxt.push_back({(now*10+i)%d,sum+i});
                }
            }
        step=nxt;
        nxt.clear();
    }
    if (!ans[0][n]) {
        cout<<-1<<endl;
        return 0;
    }
    d=0;
    while (n) {
        int x=fr2[d][n];
        res+=char(x+'0');
        d=fr1[d][n];
        n-=x;
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
}