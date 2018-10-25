#include <bits/stdc++.h>

using namespace std;

long long sum[524288];
int rao[524288];

void build(int t,int l,int r) {
    sum[t]=rao[t]=0;
    if (l == r) return;
    build(2*t,l,(l+r)/2);
    build(2*t+1,(l+r)/2+1,r);
}

long long A;

void get(int t,int l,int r,int x) {
    if (x <= 0) return;
    if (rao[t] <= x) {
        A+=sum[t];
        return;
    }
    get(2*t,l,(l+r)/2,x);
    get(2*t+1,(l+r)/2+1,r,x-rao[2*t]);
}

void upd(int t,int l,int r,int x,int y) {
    if (r < x || x < l) return;
    rao[t]++;
    sum[t]+=y;
    if (l == r)return;
    upd(2*t,l,(l+r)/2,x,y);
    upd(2*t+1,(l+r)/2+1,r,x,y);
}

long long Tim;
int n,m,i,t;
int res,D;
pair < int , int > P[200020];

int main() {
    cin>>t;
    while (t--) {
        scanf("%d%d",&n,&m);
        cin>>Tim;
        for (i=1;i<=n;i++)
            scanf("%d",&P[i].first),P[i].second=i;
        res=0; D=1;
        sort(P+1,P+n+1);
        build(1,1,n);
        for (int tsk=1;tsk<=n;tsk++) {
            upd(1,1,n,P[tsk].second,P[tsk].first);
            if (tsk != n && P[tsk].first == P[tsk+1].first)
                continue;
            int l=0; int r=rao[1]; int mi=0; int ans=0;
            while (l<=r) {
                mi=(l+r)/2;
                A=0;
                get(1,1,n,mi);
                get(1,1,n,((mi-1)/m)*m);
                if (A <= Tim) {
                    ans=mi;
                    l=mi+1;
                } else r=mi-1;
            }
            if (ans > res) {
                res=ans;
                D=P[tsk].first;
            }
        }
        printf("%d %d\n",res,D);
    }
}