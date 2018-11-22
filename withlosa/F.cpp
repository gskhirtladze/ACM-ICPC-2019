#include <bits/stdc++.h>
using namespace std;	
double dp[401][401];
int main(){
	
	int n, k;
	cin>>n>>k;
	dp[0][0]=1;
	for(int j=1;j<=k;j++) {
        dp[0][j]=dp[0][j-1]*0.5;
        for (int i=1;i<=n;i++)
            dp[i][j]=dp[i][j-1]*0.5+dp[i-1][j-1]*0.5;
        dp[n-1][j]+=dp[n][j-1]*0.5;
	}
    double ans=0;
    for (int i=1;i<=n;i++)
        ans+=i*dp[i][k];
	printf("%.7f",ans);
	
}