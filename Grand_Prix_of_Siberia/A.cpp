#include <bits/stdc++.h>

using namespace std;

int a[200020];
int n,z;

void check(int l,int r,long long X) {
    long long nam=1;
    for (int i=l;i<=r;i++) {
        nam*=a[i];
        if (abs(nam) > abs(X)) break;
    }
    if (nam == X) {
        cout<<"Yes"<<endl;
        cout<<X<<endl;
        exit(0);
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if (a[i] == 0) z++;
    }
    if (z >= 2) {
        cout<<"Yes"<<endl;
        cout<<0<<endl;
        return 0;
    }
    if (z) {
        cout<<"No"<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    check(1,n-1,a[n]);
    check(2,n,a[1]);
    cout<<"No"<<endl;
    return 0;
}