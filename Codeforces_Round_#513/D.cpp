#include <bits/stdc++.h>

using namespace std;

int n,l,r;
priority_queue < int > ql,qr;
long long ans;

int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&l,&r);
        ql.push(l);
        qr.push(r);
        ans+=l+r;
    }
    while (ql.size()) {
        l=ql.top();
        r=qr.top();
        ql.pop();
        qr.pop();
        ans-=min(l,r);
    }
    cout<<ans+n<<endl;
}