#include <bits/stdc++.h>

using namespace std;

int n,m,k,i,a,res;
int ans[200020];
priority_queue < pair < int , int > > q;
pair < int , int > b[200020];
set < int > fr;

int main() {
    cin>>n>>m>>k;
    for (i=1;i<=n;i++)
        scanf("%d",&b[i].first),b[i].second=i;
    sort(b+1,b+n+1);
    for (i=1;i<=n;i++){
        a=b[i].first;
        fr.insert(i);
        while (q.size() && -q.top().first+k<a) {
            fr.insert(q.top().second);
            q.pop();
        }
        ans[b[i].second]=*fr.begin();
        res=max(res,ans[b[i].second]);
        q.push({-a,*fr.begin()});
        fr.erase(fr.begin());
    }
    cout<<res<<endl;
    for (i=1;i<=n;i++)
        printf("%d ",ans[i]);
    cout<<endl;

}