#include <bits/stdc++.h>

using namespace std;

int f[200020];
pair < int , int > P[200020];
long long ans;
int X,Y,n,m,i,j;
vector < int > all;
map < int , int > mp;
int main() {
    cin>>X>>Y>>n>>m;
    for (i=1;i<=n;i++) {
        scanf("%d%d",&P[i].first,&P[i].second);
        all.push_back(P[i].second);
    }
    sort(all.begin(),all.end());
    for (int i=0;i<all.size();i++)
        mp[all[i]]=i+1;
    sort(P+1,P+n+1);
    for (i=1;i<=n;i++) {
        P[i].second=mp[P[i].second];
        for (j=P[i].second;j>=0;j=(j&(j+1))-1)
            ans-=f[j];
        for (j=P[i].second;j<=100000;j=j|(j+1))
            f[j]++;
    }
    mp.clear();
    all.clear();
    for (int i=0;i<=100000;i++)
        f[i]=0;
    swap(n,m);
    for (i=1;i<=n;i++) {
        scanf("%d%d",&P[i].first,&P[i].second);
        all.push_back(P[i].second);
    }
    sort(all.begin(),all.end());
    for (int i=0;i<all.size();i++)
        mp[all[i]]=i+1;
    sort(P+1,P+n+1);
    for (i=1;i<=n;i++) {
        P[i].second=mp[P[i].second];
        for (j=P[i].second;j>=0;j=(j&(j+1))-1)
            ans-=f[j];
        for (j=P[i].second;j<=100000;j=j|(j+1))
            f[j]++;
    }
    cout<<ans+1LL*n*m+1LL*n*(n+1)/2+1LL*m*(m+1)/2+1<<endl;
}