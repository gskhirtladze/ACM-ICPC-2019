#include <bits/stdc++.h>

using namespace std;

int T,x;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>T;
    while (T--) {
        scanf("%d",&x);
        if (x == 1) {
            cout<<2<<" "<<-3<<" "<<1<<endl;
            continue;
        }
        if (x == -1) {
            cout<<2<<" "<<3<<" "<<1<<endl;
            continue;
        }
        if (x > 0)
            printf("%d %d %d\n",1,-(x-1),-x);
        if (x < 0)
            printf("%d %d %d\n",1,-(x+1),+x);
    }
}