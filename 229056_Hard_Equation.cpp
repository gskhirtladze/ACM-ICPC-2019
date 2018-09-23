#include <bits/stdc++.h>

using namespace std;

map < long long , int > fix;

long long t,a,b,m,an,pw,i;

int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b>>m;
        if (b == 1) {
            cout<<0<<endl;
            continue;
        }
        fix.clear();
        long long n=sqrt(m)+2;
        an=1;
        for (i=0;i<n;i++)
            an=(an*a)%m;
        pw=1;
        for (i=0;i*n<=m;i++) {
            pw=(pw*an)%m;
            fix[pw]=i+2;
        }
        pw=b;
        
        for (i=0;i<n;i++) {

            if (fix[pw]) {
                cout<<(fix[pw]-1)*n-i<<endl;
                break;
            }
            pw=(pw*a)%m;
        }
        
    }
}