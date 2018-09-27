#include<bits/stdc++.h>

using namespace std;
int A,a,B,b,P;
int main() {
    cin>>A>>a>>B>>b>>P;
    if (A > P || B > P) {
        cout<<"No"<<endl;
        return 0;
    } 
    if (a >= B || b>=A) {
        cout<<"Yes"<<endl;
        return 0;
    }
    if (A+B <= P) {
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}