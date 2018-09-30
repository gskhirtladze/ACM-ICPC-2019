#include <bits/stdc++.h>

using namespace std;

int H,M,S;

int main() {
    scanf("%d:%d:%d",&H,&M,&S);
    int tim=H*60*60+M*60+S;
    scanf("%d:%d:%d",&H,&M,&S);
    int tim2=H*60*60+M*60+S;
    tim=tim2-tim;
    double x=360.0*tim/(24*60*60);
    printf("%.9f\n",x);
}