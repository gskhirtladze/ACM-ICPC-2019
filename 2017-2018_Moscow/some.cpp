#include <bits/stdc++.h>

using namespace std;

string s,x;
int i,j,ans,res,y;
int a[90];

int main() {
    freopen("input.txt","r",stdin);
    for (i=1;i<=73;i++) {
        string s1;
        cin>>s1>>s;
        int num=s1[1]-'0';
        if (s1.size() == 3) num=num*10+s1[2]-'0';
        for (j=1;j<=25;j++) {
            cin>>y>>x;
            //cout<<x<<" "<<y<<endl;
            ans+=y;
        }
        a[i]=ans;
        cout<<i<<" "<<num<<" "<<s1<<" "<<s<<" "<<ans<<endl;
        if (i > 10)res+=ans;
        ans=0;
    }
    cout<<res<<endl;
}