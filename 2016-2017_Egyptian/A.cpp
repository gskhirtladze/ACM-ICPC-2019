#include <bits/stdc++.h>

using namespace std;

int t,G,N,B,ans;

int main() {
    freopen("powers.in","r",stdin);
    cin>>t;
    while (t--) {
        scanf("%d",&G);
        ans=0;
        while (G--) {
            scanf("%d%d",&B,&N);
            N%=(B+1);
            if (B%2==0 && N == B)
                ans^=2; else
                ans^=N&1;
        }
        if (ans)
            printf("1\n"); else
            printf("2\n");
    }
}