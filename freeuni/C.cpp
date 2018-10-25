#include <bits/stdc++.h>

using namespace std;

int n,gc,i;
int a[200020];
int tmp[65],j;
long long ans;

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        gc=__gcd(gc,a[i]);
    }
    sort(a+1,a+n+1);
    for (i=1;i<=n;i++) {
        a[i]/=gc;
        int now=0;
        while (a[i] != 1) {
            if (a[i] % 2 != 0) {
                cout<<-1<<endl;
                return 0;
            }
            now++;
            a[i]/=2;
        }
        tmp[now]++;
    }
    for (j=0;j<=60;j++)
        tmp[j+1]+=tmp[j]/2,tmp[j]%=2;
    while (!tmp[j] && j >= 0) j--;
    j--;
    int sav=j;
    while (!tmp[j] && j >= 0) j--;
    if (j == -1) {
        cout<<0<<endl;
        return 0;
    }
    j=sav;
    while (j >= 0) {
        ans+=(1LL-tmp[j]);
        j--;
    }
    cout<<ans+1<<endl;
}