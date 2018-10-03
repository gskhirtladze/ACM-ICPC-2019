#include <bits/stdc++.h>

using namespace std;

long long n,x,t;
long long b[17];
long long a[17];
long long i,dig;

int main() {
    b[1]=9;
    for (i=2;i<=16;i++)
        b[i]=b[i-1]*10; 
    a[1]=1;
    for (i=2;i<=16;i++)
        a[i]=a[i-1]*10;
    cin>>t;
    while (t--) {
        dig=0;
        cin>>x>>n;
        n--;
        i=1;
        while (a[i]*10-1 < n) {
            dig+=i*b[i];
            i++;
        }
        dig+=(n-a[i-1]*10+1)*i;
        if (n <= 9) dig=n;
        x+=dig;
        for (i=1;i<=16;i++)
            if (x-b[i]*i > 0) { x-=b[i]*i; } else break;
        if (x%i != 0) {
            cout<<-1<<endl;
            continue;
        }
        cout<<a[i]+(x/i)-(n+1)<<endl;
    }
}