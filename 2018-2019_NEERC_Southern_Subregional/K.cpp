#include <bits/stdc++.h>

using namespace std;

long long sum[200020];
int n,k,i,lst,x;
vector < int > ans;

int main() {
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++)
        scanf("%d",&x),sum[i]=sum[i-1]+x;
    if (sum[n]%k !=0) {
        cout<<"No"<<endl;
        return 0;
    }
    for (i=1;i<=n;i++)
        if (sum[i]-sum[lst] == sum[n]/k) {
            ans.push_back(i-lst);
            lst=i;
        }
    if (lst == n) {
        cout<<"Yes"<<endl;
        for (i=0;i<k;i++)
            printf("%d ",ans[i]);
        cout<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}