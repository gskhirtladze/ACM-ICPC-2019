#include <bits/stdc++.h>

using namespace std;

int t,k,p,n;

int main() {
    cin>>t;
    while (t--) {
        scanf("%d%d%d",&k,&p,&n);
        cout<<1LL*n*(max(0LL,1LL*k-p))<<endl;
    }
}