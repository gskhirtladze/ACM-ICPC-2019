#include <bits/stdc++.h>

using namespace std;

int n,k,i,WH,BL;
int ans[500020];
priority_queue < pair < int , int > > bl,wh;
string s,q;

int main() {
    cin>>n>>k;
    cin>>s>>q;
    s="#"+s;
    q="#"+q;
    for (i=1;i<=n;i++) {
        if (q[i] != q[i-1] && q[i] == 'W') WH++;
        if (q[i] != q[i-1] && q[i] == 'B') BL++;
        if (s[i] == q[i]) {
            ans[i]=ans[i-1];
            continue;
        }
        bl.push({-(ans[i-1]+1-WH+(q[i] == 'W')),i-1});
        wh.push({-(ans[i-1]+1-BL+(q[i] == 'B')),i-1});
        while (bl.top().second+k < i) bl.pop();
        while (wh.top().second+k < i) wh.pop();
        ans[i]=min(-bl.top().first+WH,-wh.top().first+BL);
    }
    cout<<ans[n]<<endl;
}