#include <bits/stdc++.h>

using namespace std;

vector < int > pr;
int lp[10000001];
int i,j,a,b,c,d,x,m;
long long res,A,B;

int main() {
    for (i=2;i<=1000000;i++) {
        if (lp[i] == 0) {
            pr.push_back(i);
            lp[i]=i;
        }
        for (j=0;j<pr.size() && pr[j] <= lp[i] && pr[j]*i <= 10000000;j++)
            lp[pr[j]*i]=pr[j];
    }
    cin>>a>>b>>c>>d;
    for (i=1;i<=10000000;i++) {
        x=i; m=0;
        while (x != 1) {
            if (x% (lp[x]*lp[x]) == 0)
                break;
            m++;
            x/=lp[x];
        }
        if (x != 1)
            continue;
        A=b/i-(a-1)/i;
        B=d/i-(c-1)/i;
        B=d-c+1-B;
        if (m%2) res+=A*B; else res-=A*B;
    }
    if (a == 1) res+=d-c+1;
    cout<<res<<endl;
}