#include <bits/stdc++.h>

using namespace std;

vector < int > all;
int n,tot;
vector < int > from[65536];
int ans1[65536],ans2[65536];

void go2(int x,int now,int bit) {
    if (x == n) {
        tot++;
        from[bit].push_back(now);
        return;
    }
    go2(x+1,now,bit);
    if (((1<<x)&now) != 0)
        return;
    if (x != 0 && ( (bit&(1<<x-1)) != 0 || (now&(1<<(x-1))) != 0) )
        return;
    if (x != n-1 && (now&(1<<(x+1))) != 0)
        return;
    bit|=(1<<x);
    go2(x+1,now,bit);
}

void go(int x,int now) {
    if (x == n) {
        all.push_back(now);
        go2(0,now,0);
        return;
    }
    go(x+1,now);
    if (x != 0 && (now&(1<<(x-1))) != 0)
        return;
    now|=(1<<x);
    go(x+1,now);
}

int t,i,j;
int a[20][20];

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        for (i=0;i<(1<<n);i++)  
            from[i].clear(),ans1[i]=0,ans2[i]=0;
        all.clear();
        go(0,0);
        
        for (i=0;i<n;i++)
            for (j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        
        for (j=1;j<=n;j++) {
            for (int bi=0;bi<all.size();bi++) {
                int bit=all[bi];
                int now=0;
                for (int o=0;o<n;o++)
                    if (bit&(1<<o)) now+=a[o][j];
                for (int o=0;o<from[bit].size();o++)
                    ans2[bit]=max(ans2[bit],ans1[from[bit][o]]+now);
            }
            for (int bi=0;bi<all.size();bi++)
                ans1[all[bi]]=ans2[all[bi]],ans2[all[bi]]=0;
        }

        int ans=0;
        for (int bi=0;bi<all.size();bi++)
            ans=max(ans,ans1[all[bi]]);
        cout<<ans<<endl;
    }
}