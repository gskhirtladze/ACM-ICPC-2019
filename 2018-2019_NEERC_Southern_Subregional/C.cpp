#include <bits/stdc++.h>

using namespace std;

vector < pair < int , int > > upd[1000020];

long long rao[2097152];
long long sum[2097152];

void update(int t,int l,int r,int x,int y) {
    if (x < l || r < x) return;
    rao[t]+=y;
    sum[t]+=1LL*x*y;
    if (l == r) return;
    update(2*t,l,(l+r)/2,x,y);
    update(2*t+1,(l+r)/2+1,r,x,y);
}

long long B;
int A,C;

void get(int t,int l,int r,long long k) {
    if (rao[t] <= k) {
        B+=sum[t];
        return;
    }
    if (k <= 0) return;
    if (l == r) {
        B+=1LL*k*l;
        return;
    }
    get(2*t,l,(l+r)/2,k);
    get(2*t+1,(l+r)/2+1,r,k-rao[2*t]);
}

int n,k,m,l,r,c,p,i,j;
long long res;

int main() {
    cin>>n>>k>>m;
    for (i=1;i<=m;i++) {
        scanf("%d%d%d%d",&l,&r,&c,&p);
        upd[l].push_back({c,p});
        upd[r+1].push_back({-c,p});
    }
    for (i=1;i<=n;i++) {
        for (j=0;j<upd[i].size();j++)
            update(1,1,1000000,upd[i][j].second,upd[i][j].first);
        B=0;
        get(1,1,1000000,min(1LL*k,rao[1]));
        res+=B;
    }
    cout<<res<<endl;
}