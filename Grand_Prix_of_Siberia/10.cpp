#include <bits/stdc++.h>

using namespace std;

int n,m,l,i,j,k,st,x,y;
long long ans;
vector < pair < int , int > > A,B;
vector < int > all[200020];
pair < pair < int , int > , int > P[200020];

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m>>l;
    for (i=1;i<=n;i++) {
        scanf("%d%d",&P[i].first.first,&P[i].first.second);
        P[i].second=i;
    }
    for (i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        k=min(x,y);
        ans+=2LL*k*l;
        x-=k;
        y-=k;
        if (!x)
            B.push_back({y,i}); else
            A.push_back({x,i});
    }
    sort(P+1,P+n+1);
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    st=1;
    for (i=0;i<A.size();i++) {
        while (P[st].first.second == 0) st++;
        P[st].first.second--;
        all[P[st].second].push_back(A[i].second);
        ans+=2LL*P[st].first.first*A[i].first;
    }
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    st=n;
    for (i=0;i<B.size();i++) {
        while (P[st].first.second == 0) st--;
        P[st].first.second--;
        all[P[st].second].push_back(B[i].second);
        ans+=2LL*(l-P[st].first.first)*B[i].first;
    }
    cout<<ans<<endl;
    for (i=1;i<=n;i++) {
        printf("%d",(int)all[i].size());
        sort(all[i].begin(),all[i].end());
        for (j=0;j<all[i].size();j++)
            printf(" %d",all[i][j]);
        printf("\n");
    }
}