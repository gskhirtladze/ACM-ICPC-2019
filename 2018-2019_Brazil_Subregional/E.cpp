#include <bits/stdc++.h>

using namespace std;

int i,res;
bitset < 10000 > ans;
string a,b;
vector < int > pos[26];

int main() {
    for (int i=0;i<10000;i++)
        ans[i]=1;
    cin>>a>>b;
    for (int i=0;i<a.size();i++) {
        pos[a[i]-'A'].push_back(i);
    }
    for (int i=0;i<26;i++) {
        bitset < 10000 > now;
        for (int j=0;j<10000;j++)
            now[j]=1;
        for (int j=0;j<pos[i].size();j++)
            now[pos[i][j]]=0;
        for (int j=0;j<b.size();j++)
            if (b[j] == 'A'+i) {
                ans&=((now)>>j);
            }
    }
    for (int i=0;i<=a.size()-b.size();i++)
        if (ans[i]) res++;
    cout<<res<<endl;
}