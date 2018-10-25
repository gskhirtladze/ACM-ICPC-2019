#include <bits/stdc++.h>

using namespace std;

int x,y,n,i,st;
int f[200020];
int a[200020];
int ans[200929];

int main() {
    cin>>n;
    for (i=1;i<n;i++) {
        scanf("%d%d",&x,&y);
        if (x > y) swap(x,y);
        if (x == y || y != n) {
            cout<<"NO"<<endl;
            return 0;
        }
        a[i]=x;
    }
    sort(a+1,a+n);
    st=1;
    for (i=1;i<n;i++) {
        if (i == 1 || a[i] != a[i-1]) {
            ans[i]=a[i];
            f[a[i]]=1;
        } else {
            while (f[st]) st++;
            if (st > a[i]) {
                cout<<"NO"<<endl;
                return 0;
            }
            ans[i]=st;
            f[st]=1;
        }
    }
    ans[n]=n;
    cout<<"YES"<<endl;
    for (i=1;i<n;i++)
        printf("%d %d\n",ans[i],ans[i+1]);
}