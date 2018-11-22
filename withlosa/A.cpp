#include <bits/stdc++.h>

using namespace std;

int n,h,a,b,k,X;
int f[1825*100];
int main() {
    cin>>n;
    for (int k=0;k<n;k++)  {
        cin>>h>>a>>b;
        X=max(X,h);
        if (b < a) b+=h;
        for (int i=-h;i<=1825*100;i+=h)
            for (int j=a+1;j<=b-1;j++)
                if (i+j >= 0 && i+j < 1825*100) f[i+j]+=(1<<k);
    }
    for (int i=0;i<1825*X;i++) {
        if (f[i] == 0) {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"impossible"<<endl;
}