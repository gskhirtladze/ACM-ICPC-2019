#include <bits/stdc++.h>

using namespace std;

int n,t,i,q,p,v,o;
map < int , int > f;
int a[200020];

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>q;
        int tot=0;
        f.clear();
        for (i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            f[a[i]]++;
            if (a[i] != 0 && f[a[i]] == 1) tot++;
        }
        while (q--) {
            scanf("%d",&o);
            if (o == 2) {
                printf("%d\n",tot);
                continue;
            }
            scanf("%d%d",&p,&v);
            if (a[p] == 0) {
                f[0]--;
                f[v]++;
                if (f[v] == 1 && v != 0) tot++;
                a[p]=v;
                continue;
            }
            f[a[p]]--;
            if (f[a[p]] == 0) tot--;
            f[v]++;
            if (f[v] == 1 && v != 0) tot++;
            a[p]=v;
        }
    }
}