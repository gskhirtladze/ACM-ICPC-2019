#include <bits/stdc++.h>

using namespace std;
int a,b,c,d,e,f;
int main() {
    cin>>a>>b>>c>>d>>e>>f;
    cout<<max(0,d-a)+max(0,e-b)+max(0,f-c)<<endl;
}