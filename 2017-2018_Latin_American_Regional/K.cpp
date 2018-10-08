#include <bits/stdc++.h>

using namespace std;
int n,m,tot[2],i,j;
string s;
int main() {
    cin>>n>>m;
    for (i=0;i<n;i++) {
        cin>>s;
        for (j=0;j<m;j++) {
            if (s[j] == 'o')
                tot[(i^j)&1]++;
        }
    }
    if (tot[0] % 2 != tot[1] % 2) {
        cout<<"N"<<endl;
        return 0;
    }
    if ((n*m)%2) tot[1]+=2;
    if (tot[0] != tot[1])
        cout<<"N"<<endl; else
    cout<<"Y"<<endl;
}