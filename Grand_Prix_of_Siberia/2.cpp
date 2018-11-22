#include <bits/stdc++.h>

using namespace std;

#define PI 3.141592653589793238462643

double v,d,w,a,l,r,lo,hi,m,mi,A,B,C,t,mi1,mi2,h1,h2,ax,ay;

double get(double mi) {
    ax=cos(mi*PI/180)*m;
    ay=sin(mi*PI/180)*m;
    A=-0.5*ax;
    B=v;
    C=-d;
    t=(-B+sqrt((B*B-4*A*C)))/(2*A);
    return t*t*ay/2;
}
int T;
int main() {
    cin>>T;
    while (T--) {
        cin>>v>>d>>w;
        a=v*v/(2*d);
        l=0.000000000001; r=a;
        for (int it=0;it<40;it++) {
            m=(l+r)/2;
            lo=0;
            hi=90;
            for (int it2=0;it2<30;it2++) {
                mi1=(lo*2+hi)/3;
                mi2=(lo+2*hi)/3;
                h1=get(mi1);
                h2=get(mi2);
                if (h1 < h2) { lo=mi1; } else hi=mi2;
            }
            if (max(get(lo),get(hi)) >= w/2) {
                r=m;
                a=m;
            } else l=m;
        }
        printf("%.11f\n",a);
    }
}