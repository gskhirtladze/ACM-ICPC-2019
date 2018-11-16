#include <bits/stdc++.h>

using namespace std;

unsigned long long a,b,r,t,x;

int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b>>r;
        if (a > b) swap(a,b);
        if (a+b >= r) {
            cout<<"NIE"<<endl;
            continue;
        }
        if (4*b < r) {
            cout<<"TAK"<<endl;
            continue;
        }
        if (4*a >= r) {
            cout<<"NIE"<<endl;
            continue;
        }
        x=r-a-b;
        if (x%2 == 0) {
            x/=2;
            if (a*b < x*x)
                cout<<"TAK"<<endl;  else
                cout<<"NIE"<<endl; 
            continue;
        }
        x/=2;
        if (a*b <= x*x+x)
            cout<<"TAK"<<endl; else
            cout<<"NIE"<<endl; 
    }
}