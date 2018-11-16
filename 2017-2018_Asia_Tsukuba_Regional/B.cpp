#include <bits/stdc++.h>

using namespace std;

int ans[(1<<17)],res;
int x[17],y[17];
int i1,i2,i3,i4,i,j;
int h1,h2,w1,w2,k,n;
int par,num;

int sign(int A) {
    if (A < 0) return 1;
    return 0;
}

int main() {
    cin>>n;
    for (i=0;i<n;i++)
        cin>>x[i]>>y[i];
    for (j=0;j<(1<<n);res=max(res,ans[j]),j++)
        for (i1=0;i1<n;i1++)
            if (!((1<<i1)&j))
                for (i2=i1+1;i2<n;i2++)
                    if (!((1<<i2)&j)) {
        par=(1<<i1);
        par|=(1<<i2);
        num=0;
        for (i3=i1+1;i3<n;i3++)
            if (!((1<<i3)&j))
                for (i4=i3+1;i4<n;i4++)
                    if (!((1<<i4)&j))
        if (i2 != i3 && i2 != i4) {
            bool f=false;
            if (y[i1] == y[i2] && y[i3] == y[i4]) {
                ans[j+(1<<i1)+(1<<i2)+(1<<i3)+(1<<i4)]=
                max(ans[j+(1<<i1)+(1<<i2)+(1<<i3)+(1<<i4)],ans[j]+1);
                par|=(1<<i3);
                par|=(1<<i4);
                num++;
                continue;
            }
            if (x[i1] == x[i2] && x[i3] == x[i4]) {
                ans[j+(1<<i1)+(1<<i2)+(1<<i3)+(1<<i4)]=
                max(ans[j+(1<<i1)+(1<<i2)+(1<<i3)+(1<<i4)],ans[j]+1);
                par|=(1<<i3);
                par|=(1<<i4);
                num++;
                continue;
            }
            if (y[i1] == y[i2] || y[i3] == y[i4]) continue;
            if (x[i1] == x[i2] || x[i3] == x[i4]) continue;
            h1=y[i2]-y[i1];
            w1=x[i2]-x[i1];
            h2=y[i4]-y[i3];
            w2=x[i4]-x[i3];
            if (sign(h1*w1) != sign(h2*w2)) continue;
            h1=abs(h1);
            w1=abs(w1);
            h2=abs(h2);
            w2=abs(w2);
            k=__gcd(h1,w1);
            h1/=k;
            w1/=k;
            k=__gcd(h2,w2);
            h2/=k;
            w2/=k;
            if (h1 == h2 && w1 == w2){
                ans[j+(1<<i1)+(1<<i2)+(1<<i3)+(1<<i4)]=
                max(ans[j+(1<<i1)+(1<<i2)+(1<<i3)+(1<<i4)],ans[j]+1);
                par|=(1<<i3);
                par|=(1<<i4);
                num++;
            }
        }
        if ((num*(num+1))/2 >= 1)
        ans[j|par]=max(ans[j|par],ans[j]+(num*(num+1))/2);
        }
    cout<<res<<endl;
}