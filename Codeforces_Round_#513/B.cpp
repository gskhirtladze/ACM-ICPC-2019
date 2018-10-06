#include <bits/stdc++.h>

using namespace std;

long long solve(long long a) {
    long long res=0;
    while (a) {
        res+=a%10;
        a/=10;
    }
    return res;
}
long long n,a,b,k,ans1,ans2;
int main() {
    for (n=1;n<=100;n++) {
    k=9;
    int xx=n;
    int ans3=0;
    for (int i=9;xx>=i;i*=10) ans3+=9,xx-=i;
    while (xx) ans3+=xx%10,xx/=10;
    while (k <= n) k=k*10+9;
    k/=10;
    ans1=solve(k)+solve(n-k);
    ans2=0;
    for (int i=0;i<=n;i++)
     ans2=max(ans2,1LL*solve(i)+solve(n-i));
    if (ans1 != ans3) {
        cout<<"WA "<<n<<" :"<<ans1<<" "<<ans3<<endl;
    }
    }
}