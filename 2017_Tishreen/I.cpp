#include <bits/stdc++.h>

using namespace std;

int tr[2][262144];
int A;

void build(int t,int l,int r) {
    tr[0][t]=tr[1][t]=0;
    if (l == r)
        return;
    build(2*t,l,(l+r)/2);
    build(2*t+1,(l+r)/2+1,r);
}

void get_max(int h,int t,int l,int r,int X) {
    if (X < l) return;
    if (r <= X) {
        A=max(A,tr[h][t]);
        return;
    }
    get_max(h,2*t,l,(l+r)/2,X);
    get_max(h,2*t+1,(l+r)/2+1,r,X);
}

void upd_max(int h,int t,int l,int r,int X) {
    if (X < l || r < X) return;
    tr[h][t]=max(tr[h][t],A);
    if (l == r) return;
    upd_max(h,2*t,l,(l+r)/2,X);
    upd_max(h,2*t+1,(l+r)/2+1,r,X);
}

int t,i,n;
string a[200020];
pair < string , int > b[200020];

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        for (i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        for (i=1;i<=n;i++) {
            reverse(a[i].begin(),a[i].end());
            b[i]={a[i],i};
        }
        sort(b+1,b+n+1);
        build(1,1,n);
        for (i=1;i<=n;i++) {
            bool h=0;
            for (int j=0;j<b[i].first.size();j++)
                if (b[i].first[j] == 'm') h=1;
            A=0;
            get_max(h^1,1,1,n,b[i].second);
            A++;
            upd_max(h,1,1,n,b[i].second);
        }
        A=0;
        get_max(0,1,1,n,n);
        get_max(1,1,1,n,n);
        cout<<A<<endl;
    }
}