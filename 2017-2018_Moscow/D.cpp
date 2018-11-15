#include <bits/stdc++.h>

using namespace std;

int n,b,m,i,a,x;
vector < int > res;

int main() {
    cin>>n;
    for (b=2;b*b<=n;b++) {
        m=n;
        vector < int > now;
        while (m) {
            now.push_back(m%b);
            m/=b;
        }
        for (i=0;i<now.size();i++)
            if (now[i] != now[now.size()-i-1]) break;
        res.push_back(b);
    }
    for (int i=1;i*i<=n;i++)
        if (n%i == 0) {
            a=i;
            x=n/a-1;
            if (x >= 2 && a < x) {
                res.push_back(x);
            }
            a=n/i;
            x=n/a-1;
            if (x >= 2 && a < x) {
                res.push_back(x);
            }
        }
    sort(res.begin(),res.end());
    cout<<res.back()<<endl;
}
