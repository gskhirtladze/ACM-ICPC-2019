#include <bits/stdc++.h>

using namespace std;

int tr[6500000];
int sh[6500000];
int L[6500000];
int R[6500000];
int tot=1;

void upd(int t,int l,int r,int LL,int RR) {
    if (r < LL || RR < l) return;
    if (LL <= l && r <= RR) {
        tr[t]=(r-l+1)-tr[t];
        sh[t]^=1;
        return;
    }
    if (!L[t]) {
        tot++;
        L[t]=tot;
        tot++;
        R[t]=tot;
    }
    if (sh[t]) {
        sh[t]^=1;
        sh[L[t]]^=1;
        sh[R[t]]^=1;
        tr[L[t]]=((r+l)/2-l+1)-tr[L[t]];
        tr[R[t]]=(r-(r+l)/2)-tr[R[t]];
    }
    upd(L[t],l,(l+r)/2,LL,RR);
    upd(R[t],(l+r)/2+1,r,LL,RR);
    tr[t]=(tr[L[t]]+tr[R[t]]);
}

int n,i,a,b,c,d;
long long res;
pair < int , pair < int , int > > p[200020];

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        scanf("%d%d%d%d",&a,&b,&c,&d); a++; b++;
        p[i*2-1]={a,{b,d}};
        p[i*2]={c+1,{b,d}};
    }
    sort(p+1,p+2*n+1);
    for (i=1;i<=2*n;i++) {
        upd(1,0,1000000000,p[i].second.first,p[i].second.second);
        if (i+1 <= 2*n)
            res+=1LL*(p[i+1].first-p[i].first)*tr[1];
    }
    cout<<res<<endl;
}