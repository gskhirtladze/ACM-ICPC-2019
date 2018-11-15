#include <bits/stdc++.h>

#define P 1000000009

using namespace std;

int k,b,i,j,n;
long long DP[128][1000];
long long SM[128][1000];

int main() {
    cin>>k>>b;
    DP[0][0]=1;
    SM[0][0]=0;
    DP[0][1%k]+=1;
    SM[0][1%k]+=1;
    for (i=0;i+1<b;i++)
        for (j=0;j<k;j++)
            for (n=0;n<2;n++)
                DP[i+1][((j*2)+n)%k]=(DP[i+1][((j*2)+n)%k]+DP[i][j])%P,
                SM[i+1][((j*2)+n)%k]=(SM[i+1][((j*2)+n)%k]+SM[i][j]+DP[i][j]*n)%P;
    cout<<SM[b-1][0]<<endl;
}