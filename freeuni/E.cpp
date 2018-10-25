#include <bits/stdc++.h>

using namespace std;

std::set < int > xx[300020];
std::set < pair < int , int > > all;
vector < pair < int , int > > era;
bool f[300020];
int n,m,a,x,i;
vector < pair < pair < int , int > , int > > rr;
int cl[300020];
int cc[300020];

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        scanf("%d",&a); cc[i]=a;
        xx[a].insert(i);
        all.insert({i,a});
    }
    cin>>m;
    while (m--) {
        scanf("%d",&x);
        if (xx[x].size() == 0) continue;
        if (f[x]) continue;
        f[x]=1;
        int l=*xx[x].begin();
        int r=*xx[x].rbegin();
        std::set< pair < int , int > >::iterator low,up;
        low=all.lower_bound ({l,-1});
        up=all.lower_bound({r,-1});
        while (low != up) {
            xx[(*low).second].erase((*low).first);
            cc[(*low).first]=0;
            era.push_back(*low);
            low++;
        }
        xx[(*low).second].erase((*low).first);
        cc[(*low).first]=0;
        era.push_back(*low);
        for (int ii=0;ii<era.size();ii++)
            all.erase(era[ii]);
        era.clear();
        rr.push_back({{l,r},x});
    }
    for (i=rr.size()-1;i>=0;i--) {
        int l=rr[i].first.first;
        int r=rr[i].first.second;
        int x=rr[i].second;
        while (l <= r && !cl[l]) {
            cl[l]=x;
            l++;
        }
    }

    for (i=1;i<=n;i++)
        printf("%d ",cl[i]+cc[i]);
    cout<<endl;
}