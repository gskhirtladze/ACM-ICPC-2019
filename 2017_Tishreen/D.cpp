#include <bits/stdc++.h>

using namespace std;

int ret,n;
int res[20];

void go(int l,int bit,int now) {
    if (l == n) {
        ret=max(ret,__builtin_popcount(bit)+__builtin_popcount(now));
        return;
    }
    go(l+1,bit|(1<<l),now&res[l]);
    go(l+1,bit,now);
}

int t,p,a,b;

int main() {
    cin>>t;
    while (t--) {
        scanf("%d%d",&n,&p);
        for (int i=0;i<n;i++)
            res[i]=0;
        for (int i=0;i<p;i++) {
            scanf("%d%d",&a,&b); --a; --b;
            res[a]+=(1<<b);
        }
        ret=0;
        go(0,0,(1<<n)-1);
        cout<<ret<<endl;
    }
}