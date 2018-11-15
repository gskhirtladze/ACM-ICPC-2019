#include <bits/stdc++.h>

using namespace std;
int r,i,c;
int main() {
    cin>>r>>i>>c;
    if (i == 0) {
        if (r != 0) cout<<3<<endl; else
        cout<<c<<endl;
        return 0;
    }
    if (i == 1) {
        cout<<c<<endl;
        return 0;
    }
    if (i == 4) {
        if (r != 0) cout<<3<<endl; else
        cout<<4<<endl;
        return 0;
    }
    if (i == 6) cout<<0<<endl; else
    if (i == 7) cout<<1<<endl; else
    cout<<i<<endl;
}