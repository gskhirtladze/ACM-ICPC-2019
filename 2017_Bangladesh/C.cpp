#include<bits/stdc++.h>
using namespace std;

long long n,a,b,c,k,ans,AB,AC,BC;
long long P=1000000001;
vector < int > all[63211237];
int A[200020];
int main(){
    cin>>n;
    if (n == 1) {
        cin>>a;
        cout<<a%P<<endl;
        return 0;
    }
    if (n == 2) {
        cin>>a>>b;
        k=__gcd(a,b);
        a/=k; b/=k;
        a=a%P;
        b=b%P;
        k=k%P;
        a=(a*b)%P;
        a*=k;
        a%=P;
        cout<<a<<endl;
        return 0;
    }
    if (n == 3) {
        cin>>a>>b>>c;
        AB=__gcd(a,b);
        AC=__gcd(a,c);
        BC=__gcd(b,c);
        if (AB >= AC && AB >= BC) {
            
        } else 
        if (AC >= BC && AC >= AB) {
            swap(b,c);
        } else {
            swap(a,c);
        }
        AB=__gcd(a,b);
        AC=__gcd(a,c);
        BC=__gcd(b,c);
        a/=AB;
        b/=AB;
        c/=__gcd(c,AB);
        AC=__gcd(a,c);
        BC=__gcd(b,c);
        a/=AC;
        b/=BC;
        c/=AC;
        c/=BC;
        ans=c%P;
        ans*=a%P;
        ans%=P;
        ans*=b%P;
        ans%=P;
        cout<<ans<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&A[i]);
        int x=A[i];
        for (int j=2;j*j<=A[i];j++) {
            if (x%j == 0) {
                int now=1;
                while (x%j == 0) {
                    now*=j;
                    x/=j;
                }
                all[j].push_back(now);
            }
        }
        if (x != 1)
            all[x].push_back(x);
    }
    ans=1;
    for (int i=1;i<=63211236;i++) {
        if (all[i].size() == 0) continue;
        all[i].push_back(1);
        sort(all[i].begin(),all[i].end());
        int bi=all[i].back();
        all[i].pop_back();
        int sm=all[i].back();
        bi/=sm;
        bi%=P;
        ans=(1LL*ans*bi)%P;
    }
    cout<<ans<<endl;
}
