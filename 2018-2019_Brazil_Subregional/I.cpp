#include <bits/stdc++.h>

using namespace std;

int n,m,x,y,i;

int main() {
    cin>>n>>m;
    bitset < 1000 > now;
    cin>>y;
    while (y--) {
        cin>>x;
        now[x-1]=1;
    }
    bitset < 1000 > all[n];
    for (i=0;i<n;i++) {
        scanf("%d",&y);
        while (y--) {
            scanf("%d",&x);
            all[i][x-1]=1;
        }
    }
    for (i=0;i<2*n;i++) {
        if (now.count() == 0) {
            cout<<i<<endl;
            return 0;
        }
        now^=all[i%n];
    }
    cout<<-1<<endl;
}