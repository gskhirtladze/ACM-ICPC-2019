#include <bits/stdc++.h>

using namespace std;

priority_queue < pair < int , int > > q;
vector < int > g[500020];
int n,x,i,y;
vector < long long > ans;
long long res,st;
vector < int > all;
vector < pair < pair < int , int > , int > > tmp;
int ind[500020];
int srt[500020];

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        scanf("%d",&x);
        while (x--) {
            scanf("%d",&y);
            g[i].push_back(all.size());
            all.push_back(y);
            ind[all.size()-1]=i;
        }
        all.push_back(301);
        reverse(g[i].begin(),g[i].end());
    }

    for (int i=0;i<all.size();i++)
        tmp.push_back({{all[i],0},i});
    sort(tmp.begin(),tmp.end());
    srt[tmp[0].second]=0;
    for (int i=1;i<all.size();i++)
        if (tmp[i].first != tmp[i-1].first)
            srt[tmp[i].second]=srt[tmp[i-1].second]+1; else
            srt[tmp[i].second]=srt[tmp[i-1].second];

    for (int tt=0;tt<20;tt++) {
        for (int i=0;i<all.size();i++)
            tmp[i]={{ srt[i] , srt[min((int)all.size()-1,i+(1<<tt))] } ,i };
        sort(tmp.begin(),tmp.end());
        srt[tmp[0].second]=0;
        for (int i=1;i<all.size();i++)
            if (tmp[i].first != tmp[i-1].first)
                srt[tmp[i].second]=srt[tmp[i-1].second]+1; else
                srt[tmp[i].second]=srt[tmp[i-1].second];
    }
    for (int i=0;i<all.size();i++)
        if (i == 0 || all[i-1] == 301)
            q.push({-srt[i],i});
            
    while (q.size()) {
        y=q.top().first;
        x=q.top().second;
        q.pop();
        ans.push_back(all[x]);
        x=ind[x];
        g[x].pop_back();
        if (g[x].size())
            q.push({-srt[g[x].back()],g[x].back()});
    }
    reverse(ans.begin(),ans.end());
    st=365;
    for (i=0;i<ans.size();i++) {
        res=(res+ans[i]*st)%1000000007;
        st=(st*365)%1000000007;
    }
    cout<<res<<endl;
}