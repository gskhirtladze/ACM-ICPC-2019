#include <bits/stdc++.h>

using namespace std;

unsigned long long a,b,c,n,ans;

int main() {
    cin>>a>>b>>c>>n;
    if (n%2) {
        ans=(n/2)*(n/2+1);
        ans/=2;
        if (ans%3 == 0)
            ans=(ans/3)*n; else
            ans=ans*(n/3);
        if (a == b && a == c)
            cout<<ans<<endl; else
        if (a == b || b == c || a == b)
            cout<<ans*3<<endl; else
            cout<<ans*6<<endl;
    } else {
        ans=((n/2)*(n/2+1)/2-1+n/2-1);
        if (ans%3 == 0)
            ans=(ans/3)*n; else
            ans=ans*(n/3);
        if (a == b && a == c)
            cout<<ans<<endl; else
        if (a == b || b == c || a == b)
            cout<<ans*3<<endl; else
            cout<<ans*6<<endl;
    }
}