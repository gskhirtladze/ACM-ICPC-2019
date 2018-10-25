#include <bits/stdc++.h>

using namespace std;

int t,n,m,k,ans,i,z,j,now;
int mxa[300020],tot[26];
string s;

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>m>>k;
        for (i=0;i<26;i++)
            tot[i]=0;
        cin>>s;
        ans=n*m;
        for (i=0;i<s.size();i++)
            tot[s[i]-'A']++;
        for (z=0;z<26;z++) {
            mxa[0]=1;
            now=0;
            for (j=0;j<26;j++)
                if (j != z) now+=tot[j];
            
            for (j=0;j<26;j++)
                for (i=n;i>=0;i--)
                    if (j != z && tot[j] <= i)
                        mxa[i]=max(mxa[i],mxa[i-tot[j]]);
            
            for (j=0;j<=n;j++) {
                if (mxa[j] && j+tot[z] >= n)
                    ans=min(ans,(n-j)*max(0,m-now+j));
                mxa[j]=0;
            }
        }
        cout<<ans<<endl;
    }
}