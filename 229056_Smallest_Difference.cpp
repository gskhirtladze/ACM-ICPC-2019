#include <bits/stdc++.h>

using namespace std;

int n,t,i;
int x,ans;
int a[200020];

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        while (n--) {
            scanf("%d",&x);
            a[x]++;
        }
        ans=0;
        for (i=0;i<=10000;i++) {
            ans=max(ans,a[i]+a[i+1]);
            a[i]=0; 
        }
        cout<<ans<<endl;
    }
}