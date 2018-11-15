#include <bits/stdc++.h>

using namespace std;

int a[200020];
int b[200020];
int n,x,tr,fl,res,i;

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
    }
    for (x=0;x<=n;x++) {
        tr=fl=0;
        for (i=1;i<=n;i++)
            if (a[i] <= x && x <= b[i]) tr++; else fl++;
        if (tr == x) res=x;
    }
    cout<<res<<endl;
}