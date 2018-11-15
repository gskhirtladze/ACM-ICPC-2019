#include <bits/stdc++.h>

#define P 1000000009

using namespace std;

double x,y,a,b,c,d;

int main() {
    cin>>x>>y>>a>>b>>c>>d;
    if (x >= a && x <= c) {
        printf("%.3f\n",min(abs(d-y),abs(b-y)));
        return 0;
    }
    if (y >= b && y <= d) {
        printf("%.3f\n",min(abs(c-x),abs(a-x)));
        return 0;
    }
    double res=sqrt(min(abs(c-x),abs(a-x))*min(abs(c-x),abs(a-x))+min(abs(d-y),abs(b-y))*min(abs(d-y),abs(b-y)));
    printf("%.3f\n",res);
}