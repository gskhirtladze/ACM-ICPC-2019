#include <bits/stdc++.h>

using namespace std;

double a,b,r,t;

int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b>>r;
        a/=3.14159265359;
        b/=3.14159265359;
        r/=3.14159265359;
        a=sqrt(a);
        b=sqrt(b);
        r=sqrt(r);
        if (a+b+0.00000001 < r) {
            cout<<"TAK"<<endl;
        } else
            cout<<"NIE"<<endl; 
    }
}