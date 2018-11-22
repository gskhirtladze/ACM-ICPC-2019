#include <bits/stdc++.h>

using namespace std;

map < vector < int > , bool > f;
vector < int > all;
int i,j,tot;
int main() {
    for (i=0;i<100000000;i++) {
        j=i;
        all.clear();
        while (j) {
            all.push_back(j%10);
            j/=10;
        }
        int mx=0;
        for (j=0;j<all.size();j++) {
            if (all[j] > mx) break;
            mx=max(mx,all[j]+1);
        }
        if (j<all.size()) continue;
        f.clear();
        tot=0;
        for (int j=0;j<(1<<(all.size()));j++) {
            vector < int > x;
            for (int k=0;k<all.size();k++)  {
                if ((1<<k)&j)
                x.push_back(all[k]);
            }
                if (!f[x])  { tot++;
}
                f[x]=1;
            
        }
        if (tot%2 == 1) {cout<<i<<endl;}
    }
}