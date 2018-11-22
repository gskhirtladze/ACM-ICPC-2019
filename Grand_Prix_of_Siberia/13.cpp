#include <bits/stdc++.h>

using namespace std;

long long ans[1048576][27];
int to[20][27];
string s[20];
int n,i,j,k,st;

int main() {
    cin>>n;
    for (i=0;i<n;i++)
        cin>>s[i];
    for (i=0;i<n;i++) {
        for (j=0;j<26;j++) {
            st=j;
            for (k=0;k<s[i].size();k++)
                if (s[i][k]-'a' == st) {
                    if (k+1 == s[i].size()){
                        to[i][j]=26;
                        break;
                    }
                    st=s[i][k+1]-'a';
                    k++;
                }
            if (k>=s[i].size())
                to[i][j]=st;
        }
        st=s[i][0]-'a';
        for (k=1;k<s[i].size();k++)
            if (s[i][k]-'a' == st) {
                if (k+1 == s[i].size()){
                    to[i][26]=26;
                    break;
                }
                st=s[i][k+1]-'a';
                k++;
            }
        if (k>=s[i].size())
            to[i][26]=st;
    }
    
    ans[0][26]=1;
    for (i=0;i<(1<<n);i++)
        for (k=0;k<n;k++)
            if (!((1<<k)&i))
                for (j=0;j<27;j++)
                    ans[i+(1<<k)][to[k][j]]+=ans[i][j];
    long long res=1;
    for (i=1;i<=n;i++)
        res*=i;
    cout<<res-ans[(1<<n)-1][26]<<endl;
 }