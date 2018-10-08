#include <bits/stdc++.h>

using namespace std;

int k,n,i,x[20002],a;
int mi,ma,ii,ia;

int main() {
    cin>>k>>n;
    for (i=1;i<=n;i++)
        scanf("%d",&a),x[a]++;
    mi=x[1]; ii=1;
    ma=x[1]; ia=1;
    for (i=1;i<=k;i++)
        if (mi > x[i]) {
            mi=x[i];
            ii=i;
        }
    for (i=1;i<=k;i++)
        if (ma < x[i]) {
            ma=x[i];
            ia=i;
        }
    if (mi+1 == ma-1) {
        x[ii]++;
        x[ia]--;
        sort(x+1,x+k+1);
        if (x[1] != x[k]) {
            cout<<"*"<<endl;
        } else {
            cout<<"-"<<ia<<" +"<<ii<<endl;
        }
        return 0;
    }
    if (mi+1 < ma) {
        cout<<"*"<<endl;
        return 0;
    }
    x[ii]++;
    for (i=2;i<=k;i++)
        if (x[i] != x[i-1]) break;
    if (i == k+1) {
        cout<<"+"<<ii<<endl;
        return 0;
    }
    x[ii]--;
    x[ia]--;
    for (i=2;i<=k;i++)
        if (x[i] != x[i-1]){
            cout<<"*"<<endl;
            return 0;
        }
    cout<<"-"<<ia<<endl;
}