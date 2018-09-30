#include <bits/stdc++.h>

using namespace std;

int x;
double c[200020];
double R[200020];
double st,en,all;
int l,r,s,n,ans2;
double y;
int sum[200020],ans,z;
int res[200020];
vector < pair < pair < double , double > , int > > alla[200020];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n;
    for (int i=1;i<=2*n;i++) {
        scanf("%d",&x);
        if (x == 0) {
            all++;
            cin>>c[i]>>R[i];
            c[i]+=s;
            if (c[i] >= n) c[i]-=n;
            st=c[i]-R[i];
            en=c[i]+R[i];
            l=ceil(st);
            r=int(en);
            for (int j=l;j<r;j++)
                sum[j]+=all,res[j]++;
            if (l > r) {
                alla[int(l)].push_back({{st,en},all} );
            } else {
            if (l != st) {
                alla[l-1].push_back({{st,l},all});
            }
            alla[r].push_back({{r,en},all});
            }
        } else {
            cin>>y;
            z=int(y);
            ans=sum[z];
            int ans2=res[z];
            for (int x=0;x<alla[int(y)].size();x++)
                if (alla[int(y)][x].first.first <= z && alla[(int(y))][x].first.second >= z) ans+=alla[int(y)][x].second,ans2++;
            cout<<ans2<<endl;
            s=(s+ans)%n;
        }
    }
}