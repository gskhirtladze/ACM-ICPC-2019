#include <bits/stdc++.h>

using namespace std;

int w,l,n,i,j,tot,all;
vector < int > mp[300200];
string tx[300200];
int sz[300200];
map < string , int > fx;
map < vector < int > , bool > used;
string s,q,a;
vector < int > text,res;

int main() {
    cin>>w>>l>>n;
    while (n--){
        cin>>a;
        if (!fx[a]) {
            all++;
            fx[a]=all;
            tx[all]=a;
            sz[all]=a.size();
        }
        getline(cin,s);
        s=s+" ";
        q="";
        for (i=1;i<s.size();i++) 
            if (s[i] == ' ') {
                if (!fx[q]) {
                    all++;
                    fx[q]=all;
                    tx[all]=q;
                    sz[all]=q.size();
                }
                mp[fx[a]].push_back(fx[q]);
                q="";
                continue;
        } else q+=s[i];
    }
    while (getline(cin,q)) {
        q+=" ";
        s="";
        for (i=0;i<q.size();i++) 
            if (q[i] == ' ') {
                if (!fx[s]) {
                    all++;
                    fx[s]=all;
                    tx[all]=s;
                    sz[all]=s.size();
                }
                text.push_back(fx[s]);
                tot+=s.size();
                s="";
                continue;
        } else s+=q[i];
        text.push_back(0);
    }
    while (tot < l) {
        if (used[text]) {
            cout<<"No result"<<endl;
            return 0;
        }
        used[text]=1;
        vector < int > res;
        for (i=0;i<text.size();i++) {
            if (mp[text[i]].size() == 0) {
                res.push_back(text[i]);
                continue;
            }
            for (j=0;j<mp[text[i]].size();j++)
                res.push_back(mp[text[i]][j]);
        }
        tot=0;
        for (i=0;i<res.size();i++)
            tot+=sz[res[i]];
        text=res;
    }
    int now=0;
    for (i=0;i<text.size();i++) {
        if (text[i] == 0) {
            if (now != 0) { 
                cout<<endl;
                now=0;
            }
            continue;
        }
        if (now == 0) {
            cout<<tx[text[i]];
            now+=sz[text[i]];
            continue;
        }
        if (now+1+sz[text[i]] > w) {
            cout<<endl;
            now=0;
            i--;
            continue;
        }
        cout<<" "<<tx[text[i]];
        now+=sz[text[i]]+1;
    }
}