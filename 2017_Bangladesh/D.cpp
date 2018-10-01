#include <bits/stdc++.h>

using namespace std;

int t,n,i,rest,tot;
int a[200020];

int main() {
    cin>>t;
    while (t--) {
        tot++;
        cin>>n;
        int ans=0,res=0;
        for (i=1;i<=n;i++)
            cin>>a[i],ans^=a[i];
        for (i=1;i<=n;i++) {
            rest=ans^a[i];
            if (a[i] > rest)
                res++;
        }
        cout<<"Case "<<tot<<": "<<res<<endl;
    }
}