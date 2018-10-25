#include <bits/stdc++.h>

using namespace std;

vector < int > a,b,ze;
long long ans,res;
int tot,now,n,i,y,j;
string x;

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x>>y;
        if (x == "11") {
            ans+=y;
            tot++;
        }
        if (x == "10") {
            a.push_back(y);
            ans+=y;
        }
        if (x == "01") {
            b.push_back(y);
            ans+=y;
        } 
        if (x == "00") {
            ze.push_back(y);
        }
    }
    sort(ze.begin(),ze.end());
    reverse(ze.begin(),ze.end());
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for (int j=0;j<=ze.size();j++) {
        if (j != 0) {
            ans+=ze[j-1];
            now++;
        }
        if (now > tot) break;
        while (abs((int)a.size()-(int)b.size()) > tot-now) {
            if (a.size() > b.size()) {
                ans-=a.back();
                a.pop_back();
            } else {
                ans-=b.back();
                b.pop_back();
            }
        }
        res=max(res,ans);
    }
    cout<<res<<endl;
}