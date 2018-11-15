#include <bits/stdc++.h>

#define E9 1000000002

using namespace std;

set < pair < int , int > > st[500020];
std::set< pair < int , int > >::iterator itlow,ithigh;
pair < int , int >  all[500020];
int l,r,ans,now,i,t,m,n,h,p;
char ch;
int x,y,X,Y,dlt;

inline bool getR() {
    ithigh=st[m].lower_bound({h,E9});
    itlow=ithigh;
    itlow--;
    x=(*itlow).second;
    y=(*itlow).first;
    X=(*ithigh).second;
    Y=(*ithigh).first;
    dlt=(Y-y+X-x)/2;
    if (dlt >= h-y)
        return (x+h-y)<p; else
        return (X+Y-h)<p;
}
int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        p=0;
        while (!(ch >= '0' && ch <= '9')) ch=getchar();
        while ((ch >= '0' && ch <= '9')) p=(p<<3)+(p<<1)+ch-'0',ch=getchar();
        t=0;
        while (!(ch >= '0' && ch <= '9')) ch=getchar();
        while ((ch >= '0' && ch <= '9')) t=(t<<3)+(t<<1)+ch-'0',ch=getchar();
        all[i]={p,t};
    }
    sort(all+1,all+n+1);
    for (i=1;i<=n;i++)
        if (all[i] != all[i-1]) {
            p=all[i].first;
            h=all[i].second;
            l=1; r=now; ans=now+1;
            while (l <= r) {
                m=(l+r)/2;
                if (getR()) {
                    l=m+1;
                } else {
                    ans=m;
                    r=m-1;
                }
            }
            if (ans == now+1) {
                now++;
                st[now].insert({-h,p});
                st[now].insert({E9*2-h,p});
            }
            st[ans].insert({h,p});
    }
    cout<<now<<endl;
}