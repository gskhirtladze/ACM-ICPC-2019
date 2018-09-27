#include <bits/stdc++.h>

using namespace std;

int n,t;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        int ans=0,x;
        while (n--) {
            scanf("%d",&x);
            ans+=(x!=0);
        }
        cout<<ans<<endl;
    }
}