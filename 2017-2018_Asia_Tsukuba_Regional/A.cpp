#include <bits/stdc++.h>

using namespace std;

unsigned long long res,ans;
long long i,l,k,rao,tot,bl,r;

int main() {
    cin>>l>>k;
    for (;l>=1;l--)
    for (rao=1;rao<=l;rao+=2) {
        tot=(l-rao)/(k-1);
        if ((l-rao) % (k-1) != 0)
            continue;
        bl=(rao+1)/2;
        if (tot > bl)
            continue;
        tot=max(tot,bl-tot);
        ans=1;
        r=1;
        for (i=tot+1;i<=bl;i++) {
            ans*=i;
            if (r <= bl-tot && ans%r == 0) {
                ans/=r;
                r++;
            }
        }
        res+=ans;
    }
    cout<<res<<endl;
}