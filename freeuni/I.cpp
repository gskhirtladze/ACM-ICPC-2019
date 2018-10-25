#include <bits/stdc++.h>

using namespace std;
long long a,b,x,y,t;
int main() {
    cin>>a>>b>>x>>y;
	t=__gcd(x,y);
	x/=t,y/=t;
	cout<<min(a/x,b/y)<<endl;

}