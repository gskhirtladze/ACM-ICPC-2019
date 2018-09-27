#include <bits/stdc++.h>

#define pi 3.14159265359
using namespace std;

int t;
double D,R,r,l,A;
int a,b,d;

int main() {
    cin>>t;
    while (t--) {
        scanf("%d%d%d",&a,&b,&d);
        D=d;
        R=D/2;
        l=sqrt(2*R*R);
        r=l/2;
        A=4*(pi*r*r/2)- ( pi*R*R-l*l ) ;
        printf("%.8f\n",A);
    }
}