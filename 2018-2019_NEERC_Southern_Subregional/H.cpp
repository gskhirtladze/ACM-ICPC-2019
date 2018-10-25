#include <bits/stdc++.h>

using namespace std;

map < string , string > ans;
map < string , int > res;
int n,i,q;
string s;

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>s;
        vector < string > all;
        for (int j=0;j<s.size();j++) {
            string q="";
            for (int k=j;k<s.size();k++) {
                q+=s[k];
                all.push_back(q);
                ans[q]=s;
            }
        }
        sort(all.begin(),all.end());
        res[all[0]]++;
        for (int j=1;j<all.size();j++)
            if (all[j] != all[j-1])
                res[all[j]]++;
    }
    cin>>q;
    while (q--) {
        cin>>s;
        if (res[s] == 0) {
            cout<<"0 -"<<endl;
            continue;
        }
        cout<<res[s]<<" "<<ans[s]<<endl;
    }
}