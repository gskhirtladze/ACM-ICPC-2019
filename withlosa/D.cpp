#include <bits/stdc++.h>

using namespace std;

string s,q;
vector < pair < int , int > > ans;

void my_sort(int l,int r) {
    if (l >= r) return;
    int m=(r+l)/2;
    vector < vector < int > > tot(26);
    for (int i=l;i<=r;i++) {
        if (s[i] > q[m] && i <= m)
            tot[s[i]-'a'].push_back(i);
        if (s[i] < q[m] && i > m)
            tot[s[i]-'a'].push_back(i);
        if (s[i] == q[m])
            tot[s[i]-'a'].push_back(i);
    }
    sort(tot[q[m]-'a'].begin(),tot[q[m]-'a'].end());
    reverse(tot[q[m]-'a'].begin(),tot[q[m]-'a'].end());
    int lst=25;
    for (int i=0;i<q[m]-'a';i++) {
        for (int j=0;j<tot[i].size();j++) {
            while (!tot[lst].size()) lst--;
            ans.push_back({tot[i][j],tot[lst].back()});
            swap(s[tot[lst].back()],s[tot[i][j]]);
            tot[lst].pop_back();
        }
        tot[i].clear();
    }
    reverse(tot[q[m]-'a'].begin(),tot[q[m]-'a'].end());
    lst=0;
    for (int i=q[m]-'a'+1;i<26;i++) {
        for (int j=0;j<tot[i].size();j++) {
            while (!tot[lst].size()) lst++;
            ans.push_back({tot[lst].back(),tot[i][j]});
            swap(s[tot[lst].back()],s[tot[i][j]]);
            tot[lst].pop_back();
        }
        tot[i].clear();
    }
    my_sort(l,m);
    my_sort(m+1,r);
}

int main() {
    cin>>s;
    q=s;
    sort(q.begin(),q.end());
    my_sort(0,s.size()-1);
    for (int i=ans.size()-1;i>=0;i--)
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
}