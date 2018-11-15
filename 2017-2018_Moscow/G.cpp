#include <bits/stdc++.h>

using namespace std;

map < long long , bool > f;
int ans;
string s;
vector < long long > res;
long long now,num,now2;
int n;

int main() {
    cin>>s;
    s+=".";
    for (int i=0;i<s.size();i++)
        if (s[i] == '.' || s[i] == '/') {
            res.push_back(now);
            now=0;
        }  else now=now*10+s[i]-'0';
    now=res[0]*256*256*256+res[1]*256*256+res[2]*256+res[3];
    num=res[4];
    num=32-num;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s;
        res.clear();
        s+=".";
        now2=0;
        for (int ii=0;ii<s.size();ii++)
            if (s[ii] == '.' || s[ii] == '/') {
                res.push_back(now2);
                now2=0;
            }  else now2=now2*10+s[ii]-'0';
        now2=res[0]*256*256*256+res[1]*256*256+res[2]*256+res[3];
        if ( (now2>>num) != (now>>num)) continue;
        if ( (__builtin_popcount(now2%(1LL<<num))%num == 0 ) ) {
            cout<<-1<<endl;
            return 0;
        }if (f[now2]) {
        } else  {
            f[now2]=1;
            ans++;
        }
    }
    cout<<(1LL<<num)-2-ans<<endl;

}