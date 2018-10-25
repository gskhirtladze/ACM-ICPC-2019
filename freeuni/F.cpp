#include <bits/stdc++.h>

using namespace std;
int i,sum1,sum2,sum,t,x,n;
vector < int >  res[1000020];
int ans[1000020];
int main() {
    for (i=0;i<1000000;i++) {
        sum=i;
        sum1=(i%1000000)/100000+(sum%100000)/10000+(sum%10000)/1000;
        sum2=(i%1000)/100+(sum%100)/10+(sum%10)/1;
        ans[i]=abs(sum1-sum2);
        res[ans[i]].push_back(i);
    }
    cin>>t;
    while (t--) {
        scanf("%d",&n);
        x=ans[n];
        int sum=0;
        for (int j=0;j<x;j++) {
        int l=0; int r=res[j].size()-1; int m=0; int ans=0;
        while (l <= r) {
            m=(l+r)/2;
            if (res[j][m] < n) { ans=m+1; l=m+1;} else r=m-1;
        }
        sum+=ans;
        }
        printf("%d\n",sum);
        
    }

}