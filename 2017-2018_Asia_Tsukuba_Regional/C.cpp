#include <bits/stdc++.h>

using namespace std;

long long b[200020];
int a[200020];
int t,n,i;

int main() {
    cin>>n>>t;
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i]=b[i-1]+a[i],a[i]=max(a[i],a[i-1]);
    for (i=1;i<=n;i++) {
        if (t < b[i] ) {
            printf("1\n");
            continue;
        }
        printf("%d\n",(int)(t-b[i])/a[i]+2);
    }
}