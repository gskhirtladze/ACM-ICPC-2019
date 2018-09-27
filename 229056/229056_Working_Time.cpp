#include <bits/stdc++.h>

using namespace std;

int t,n,m,i;

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>m;
        int res=0;
        for (i=1;i<=n;i++) {
            int a,b,c,d;
            scanf("%d:%d %d:%d",&a,&b,&c,&d);
            res+=c*60+d-a*60-b;
        }
        if (res >= m*60)
            cout<<"YES"<<endl; else
            cout<<"NO"<<endl;
    }
}