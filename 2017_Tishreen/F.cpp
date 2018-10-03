#include <bits/stdc++.h>

using namespace std;

int t,k,p,n,a[55],i,x;

int main() {
    cin>>t;
    while (t--) {
        scanf("%d",&n);
        for (i=1;i<=n;i++) a[i]=0;
        for (i=1;i<n;i++) {
            scanf("%d",&x);
            a[x]++;
        }
        i=1;
        while (a[i]) i++;
        cout<<i<<endl;
    }
}