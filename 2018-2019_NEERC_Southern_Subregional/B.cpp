#include <bits/stdc++.h>

using namespace std;

long long n,num,i;
string s;
int all;
bool cant[6600002];
bool nnow[6600002];
bool nnoww[6600002];
bool era[6600002];
int L[6600002][2];

void add(int now,int l,string s,char x) {
    if (x == '+') {
        cant[now]=true;
        if (nnow[now]) {
            cout<<-1<<endl;
            exit(0);
        }
    }
    if (x == '-') {
        era[now]=true;
        if (nnoww[now]) {
            cout<<-1<<endl;
            exit(0);
        }
    }
    if (l == s.size()) {
        if (x == '-') {
            if (cant[now]) {
                cout<<"-1"<<endl;
                exit(0);
            }
            nnow[now]=true;
        }
        if (x == '+') {
            if (era[now]) {
                cout<<"-1"<<endl;
                exit(0);
            }
            nnoww[now]=true;
        }
        return;
    }
    int X=s[l]-'0';
    if (!L[now][X])
        L[now][X]=++all;
    add(L[now][X],l+1,s,x);
}

vector < pair < long long , int > > ans;

void go(int now,long long num,long long dp) {
    if (now == 0) return;
    if (!era[now]) return;
    if (!cant[now]) {
        ans.push_back({num<<(32LL-dp),dp});
        return;
    }
    go(L[now][0],num*2+0,dp+1);
    go(L[now][1],num*2+1,dp+1);
}

int main() {
    all=1;
    cin>>n;
    while (n--) {
        cin>>s;
        s=s+"#";
        vector < long long > now;
        num=0;
        for (i=1;i<s.size();i++) {
            if (!(s[i] >= '0' && s[i] <= '9')) {
                now.push_back(num);
                num=0;
            } else num=num*10+s[i]-'0';
        }
        num=((((now[0]*256+now[1])*256)+now[2])*256+now[3]);
        long long rao=32;
        if (now.size() == 5) rao=now[4];
        num>>=32LL-rao;
        string ret="";
        while (rao--) {
            ret+=char('0'+num%2);
            num/=2;
        }
        reverse(ret.begin(),ret.end());
        add(1,0,ret,s[0]);
    }
    go(1,0,0);
    long long A,B,C,D;
    cout<<ans.size()<<endl;
    for (int i=0;i<ans.size();i++) {
        A=ans[i].first/256/256/256;
        B=(ans[i].first/256/256)%256;
        C=(ans[i].first/256)%256;
        D=ans[i].first%256;
        cout<<A<<"."<<B<<"."<<C<<"."<<D<<"/"<<ans[i].second<<endl;
    }
}