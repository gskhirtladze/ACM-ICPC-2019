#include <bits/stdc++.h>

using namespace std;

string s,q;
int now,a,b,t,n;
long long res;

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        s=q="";
        getchar();
        for (int i=0;i<n;i++)
            s+=getchar();
        getchar();
        for (int i=0;i<n;i++)
            q+=getchar();
        a=b=0;
        s+="1";
        q+="1";
        bool f=1;
        for (int i=0;i<s.size();i++)
            if (s[i] == q[i]) {
                if (now) {
                    if (a && b) f=0;
                    if (!a) a=now; else b=now;
                    now=0;
                }
            } else now++;
        if (a && b)
            res=6; else
        if (a)
            res=2*(a-1)+2*(n-a); else
            res=1LL*n*(n+1)/2;
        if (!f) res=0;
        printf("%lld\n",res);
    }
}