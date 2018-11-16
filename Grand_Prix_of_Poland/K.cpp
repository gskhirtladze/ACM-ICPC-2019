#include <bits/stdc++.h>

using namespace std;

string s;
int l,r,i;
long long ans1,ans2;
int HI[1000020];
int LO[1000020];

int main() {
    cin>>s;

    for (i=0;i<s.size();i++) {
        if (s[i] == '+') {
            l++;
            r++;
        }
        if (s[i] == '-') {
            l--;
            r--;
        }
        if (s[i] == '_') {
            l--;
            r++;
        }
        l=max(l,0);
        if (r < 0) {
            cout<<"NIE"<<endl;
            return 0;
        }
        HI[i]=r;
        LO[i]=l;
    }
    l=0; r=0;
    for (i=s.size()-1;i>=0;i--) {
        LO[i]=max(LO[i],l);
        HI[i]=min(HI[i],r);
        if (s[i] == '+') {
            l--;
            r--;
        }
        if (s[i] == '-') {
            l++;
            r++;
        }
        if (s[i] == '_') {
            l--;
            r++;
        }
        l=max(l,0);
        if (r < 0) {
            cout<<"NIE"<<endl;
            return 0;
        }
        if (LO[i] > HI[i]) {
            cout<<"NIE"<<endl;
            return 0;
        }
        ans1+=LO[i];
        ans2+=HI[i];
    }
    cout<<ans1<<" "<<ans2<<endl;
}