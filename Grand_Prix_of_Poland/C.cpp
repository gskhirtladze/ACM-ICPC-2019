#include <bits/stdc++.h>

using namespace std;

long long n,i,k,a[200020],b[200020];

int main() {
    cin>>n;
    for (i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for (i=1;i<=n;i++)
        scanf("%lld",&b[i]),k=__gcd(k,a[i]-b[i]);
    cout<<k<<endl;
}