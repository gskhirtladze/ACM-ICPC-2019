#include <bits/stdc++.h>

using namespace std;

string lst,s;
int ans;

int main() {
    string lst="";
    string lst2="";
    while (getline(cin,s)) {
        if (s[0] < lst[0]) ans++;
        lst2=lst;
        lst=s;
    }
    if (lst2 != "" && lst[0] < lst2[0]) ans--;
    cout<<ans<<endl;
}