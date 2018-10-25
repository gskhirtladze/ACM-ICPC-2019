#include <bits/stdc++.h>

using namespace std;

long long n,k,i,y,ans;
int x;

int main() {
    cin>>n>>k;
    for (i=1;i<=n;i++) {
        scanf("%d",&x);
        if (y) {
            ans++;
            x=max(0LL,x+y-k);
        }
        ans+=x/k;
        x%=k;
        y=x;
    }
    if (y) ans++;
    cout<<ans<<endl;
}