#include <bits/stdc++.h>

using namespace std;

vector < int > na;

bool rst[1200][1200];
int fr[1200][1200];
string s;
int n,i,j;

int main() {
    cin>>s>>n;
    na.push_back(1);
    for (i=1;i<s.size();i++)
        na.push_back((na.back()*10)%n);
    reverse(na.begin(),na.end());
    rst[s.size()][0]=true;
    for (i=s.size()-1;i>=0;i--) {
        vector < int > x;
        if (s[i] == '?') {
            int st=0; if (!i) st++;
            for (int j=st;j<=9;j++)
                x.push_back(j);
        } else
        x.push_back(s[i]-'0');
        for (int j=0;j<x.size();j++)
            for (int k=0;k<n;k++) 
                if (!rst[i][k]) {
                int ne=k-(x[j]*na[i])%n;
                if (ne < 0) ne+=n;
                if (rst[i+1][ne]) {
                    rst[i][k]=1;
                    fr[i][k]=x[j];
                }
            }
    }
    if (!rst[0][0]) {
        cout<<"*"<<endl;
        return 0;
    }
    i=0; j=0;
    while (i != s.size()) {
        cout<<fr[i][j];
        j=j-(fr[i][j]*na[i])%n;
        if (j<0) j+=n;
        i++;
    }
    cout<<endl;

}