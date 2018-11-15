#include <bits/stdc++.h>

using namespace std;

vector < int > pr;
int lp[1000001];
int ans[1000001];
int i,j,x;

int main() {
    for (i=2;i<=1000000;i++) {
        if (lp[i] == 0) {
            pr.push_back(i);
            lp[i]=i;
        }
        for (j=0;j<pr.size() && pr[j] <= lp[i] && pr[j]*i <= 1000000;j++)
            lp[pr[j]*i]=pr[j];
    }
    cin>>x;
    ans[4]=1;
    for (i=6;i<=x;i+=2) {
        for (j=i-3;;j-=2)
            if (lp[j] == j && lp[i-j] == i-j) {
                ans[i]=ans[j*2-i]+1;
                break;
            }
    }
    cout<<ans[x]<<endl;
}