#include <bits/stdc++.h>

#define X first.first
#define Y first.second

using namespace std;

pair < pair < int , int > , int > P[200020];
map < int , long long > mp;
long long res[200020];
int n,k,i,j,l;

int main() {
    cin>>n;
    for (i=1;i<=n;i++)
        scanf("%d%d%d",&P[i].X,&P[i].Y,&P[i].second);
    sort(P+1,P+n+1);
    for (l=1;l<=n;l++)
        if (l == 1 || P[l].X != P[l-1].X) {
            for (i=l;i<=n && P[i].X == P[l].X;i++) {
                for (int x=P[i].Y-1;x>=0;x=(x&(x+1))-1)
                    res[i]=max(res[i],mp[x]);
                j=i;
                while (j <= n && P[j].first == P[i].first)
                    res[i]+=P[j].second,j++;
                i=j-1;
            }
            for (i=l;i<=n && P[i].X == P[l].X;i++) {
                for (int x=P[i].Y;x<=1000000000;x=(x|(x+1)))
                    mp[x]=max(res[i],mp[x]);
            }
        }
    for (i=1;i<=n;i++)
        res[i]=max(res[i],res[i-1]);
    cout<<res[n]<<endl;
}