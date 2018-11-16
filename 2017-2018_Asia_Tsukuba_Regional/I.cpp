#include <bits/stdc++.h>

using namespace std;

int tr[524288];

void upd(int t,int l,int r,int x) {
    if (r < x || x < l) return;
    tr[t]++;
    if (l == r) return;
    upd(2*t,l,(l+r)/2,x);
    upd(2*t+1,(l+r)/2+1,r,x);
}

int get(int t,int l,int r,int x) {
    if (r < x) return 0;
    if (x <= l) return tr[t];
    return get(2*t,l,(l+r)/2,x)+get(2*t+1,(l+r)/2+1,r,x);
}

int n,i,r,ans1,ans2;
pair < int , int > P[200020];
pair < int , int > C[200020];
int a[200020],b[200020];
int tot[200020];

int main() {
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
        tot[a[i]]++;
        tot[b[i]]--;
        b[i]--;
        P[i].first=a[i];
        P[i].second=b[i];
        C[i].first=b[i];
        C[i].second=a[i];
    }
    sort(P+1,P+n+1);
    sort(C+1,C+n+1);
    r=1;
    for (i=1;i<=n;i++) {
        while (r <= n && P[r].first <= C[i].first) {
            upd(1,1,100000,P[r].second);
            r++;
        }
        ans1=max(ans1,get(1,1,100000,C[i].second));
    }
    for (i=1;i<=100000;i++) {
        tot[i]+=tot[i-1];
        ans2=max(ans2,tot[i]);
    }
    cout<<ans1<<" "<<ans2<<endl;
}