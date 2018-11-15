#include <bits/stdc++.h>

using namespace std;

int va,vb,vc,v1,v2,v3,v4;
int p[200020];
char a[200020];
int all[200020];
int i,j,num;

int main() {
    cin>>va>>vb>>vc;
    cin>>v1>>v2>>v3>>v4;
    for (i=1;i<=3;i++)
        for (j=1;j<=3;j++) {
            num++;
            cin>>a[num];
        }
    for (i=1;i<=9;i++)
        p[i]=i;
    while (true) {
        bool f=true;
        for (i=1;i<=9;i++)
            all[a[i]]+=p[i];
        if (all['A'] != va || all['B'] != vb || all['C'] != vc) f=false;
        for (i=1;i<=9;i++)
            all[a[i]]-=p[i];
        if (p[1] + p[2] + p[4] + p[5] != v1) f=false;
        if (p[3] + p[2] + p[6] + p[5] != v2) f=false;
        if (p[7] + p[8] + p[4] + p[5] != v3) f=false;
        if (p[9] + p[8] + p[6] + p[5] != v4) f=false;
        if (f) {
            for (i=1;i<=3;i++)
                cout<<p[i];
            cout<<endl;
            for (i=1;i<=3;i++)
                cout<<p[3+i];
                cout<<endl;
            for (i=1;i<=3;i++)
                cout<<p[6+i];
            cout<<endl;
            return 0;

        }
        if (!next_permutation(p+1,p+10)) break;
    }
    cout<<"NIE"<<endl;
}