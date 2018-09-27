#include<bits/stdc++.h>

using namespace std;
int a[200020];
int tot[200200];
int ans,i,n,d;
int main() {
    cin>>n>>d;
    for (i=1;i<=n;i++) {
        cin>>a[i];
        tot[a[i]]++;
    }
    for (i=0;i<=n;i++) {
        if (tot[i] <= d) 
            continue;
        ans+=(tot[i]-d+d-2)/(d-1);
    }
    cout<<ans<<endl;
}