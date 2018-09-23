#include <bits/stdc++.h>

using namespace std;

int t;
int i,n,all;
int pos[200020];
int a[200020];
int b[200020];
int ROOT[200020];
int L[2000020];
int R[2000020];
int SUM[2000020];

void build(int t,int l,int r) {
    SUM[t]=0;
    if (l == r) return;
    all=max(all,t);
    L[t]=2*t;
    R[t]=2*t+1;
    build(2*t,l,(l+r)/2);
    build(2*t+1,(l+r)/2+1,r);
}

int getless(int t,int l,int r,int x) {
    if (x < l) return 0;
    if (r <= x) return SUM[t];
    return getless(L[t],l,(l+r)/2,x)+getless(R[t],(l+r)/2+1,r,x);
}

int getmore(int t,int l,int r,int x) {
    if (r < x) return 0;
    if (x <= l) return SUM[t];
    return getmore(L[t],l,(l+r)/2,x)+getmore(R[t],(l+r)/2+1,r,x);
}

int upd(int t,int l,int r,int x) {
    if (x < l || r < x) return t;
    int now=++all;
    if (l == r) {
        SUM[now]=SUM[t]+1;
        return now;
    }
    L[now]=upd(L[t],l,(l+r)/2,x);
    R[now]=upd(R[t],(l+r)/2+1,r,x);
    SUM[now]=SUM[L[now]]+SUM[R[now]];
    return now;
}

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        long long ans=0;
        for (i=1;i<=n;i++)
            scanf("%d",&a[i]),pos[a[i]]=i;
        for (i=1;i<=n;i++)
            scanf("%d",&b[i]),b[i]=pos[b[i]];
        all=0;
        build(1,1,n);
        for (i=1;i<=n;i++)
            ROOT[i]=upd(ROOT[i-1],1,n,b[i]);
        for (i=1;i<=n;i++) {
            ans+=b[i]-1-getless(ROOT[i],1,n,b[i]-1);
            ans+=getmore(ROOT[i-1],1,n,b[i]+1);
        }
        cout<<ans/2<<endl;
    }
}