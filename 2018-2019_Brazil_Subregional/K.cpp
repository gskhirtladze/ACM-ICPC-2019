#include <bits/stdc++.h>

#define X second.first
#define Y second.second
#define R first

using namespace std;

pair < double , pair < double , double > > P[200000];

double dst(double A,double B,double C,double D) {
    return sqrt( (A-C)*(A-C) + (D-B)*(D-B) );
}
int n,ans;

int main() {
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>P[i].X>>P[i].Y>>P[i].R;
    sort(P+1,P+n+1);
    for (int i=1;i<=n;i++) {
        for (int j=i-1;j>=1;j--) {
            if (dst(-25,-25,25,25)+P[j].R <= P[i].R) break;
            if (dst(P[i].X,P[i].Y,P[j].X,P[j].Y)+P[j].R > P[i].R) ans+=2;
            if (ans > 2*n) {
                cout<<"greater"<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
}