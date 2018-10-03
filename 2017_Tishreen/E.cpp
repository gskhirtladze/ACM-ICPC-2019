#include <bits/stdc++.h>

using namespace std;

int r,c,m,t;

int clc(int A,int B,int C) {
    for (int x=0;x<c;x++) {
        if (((1<<x)&B)) continue;
        int t=0;
        if (x && ((1<<(x-1))&A)) t++;
        if (x && ((1<<(x-1))&B)) t++;
        if (x && ((1<<(x-1))&C)) t++;
        if (x+1<c && ((1<<(x+1))&A)) t++;
        if (x+1<c && ((1<<(x+1))&B)) t++;
        if (x+1<c && ((1<<(x+1))&C)) t++;
        if (((1<<x)&A)) t++;
        if (((1<<x)&C)) t++;
        if (t > m) return 0;
    }
    return 1;
}
int che(int A,int B,int C) {
    for (int x=0;x<c;x++) {
        if (!((1<<x)&B)) continue;
        int t=0;
        if (x && !((1<<(x-1))&A)) t++;
        if (x && !((1<<(x-1))&B)) t++;
        if (x && !((1<<(x-1))&C)) t++;
        if (x+1<c && !((1<<(x+1))&A)) t++;
        if (x+1<c && !((1<<(x+1))&B)) t++;
        if (x+1<c && !((1<<(x+1))&C)) t++;
        if (!((1<<x)&A)) t++;
        if (!((1<<x)&C)) t++;
        if (t == 0) return 0;
    }
    return 1;
}

int i,j,k,o;
int DP[8][128][128];

int main() {
    cin>>t;
    while (t--) {
        scanf("%d%d%d",&r,&c,&m);
        for (i=0;i<(1<<c);i++)
            for (j=0;j<(1<<c);j++) {
                DP[2][i][j]=0;
                if (!clc(0,i,j)) continue;
                if (!che((1<<c)-1,i,j)) continue;
                DP[2][i][j]=__builtin_popcount(i)+__builtin_popcount(j);
            }
        for (int o=3;o<=r;o++) {
            for (i=0;i<(1<<c);i++)
                for (j=0;j<(1<<c);j++) {
                    DP[o][i][j]=0;
                    for (k=0;k<(1<<c);k++) {
                        if (!clc(k,i,j)) continue;
                        if (!che(k,i,j)) continue;
                        DP[o][i][j]=max(DP[o][i][j],DP[o-1][k][i]+__builtin_popcount(j));
                    }
                }
        }
        int res=0;
        
        for (i=0;i<(1<<c);i++)
            for (j=0;j<(1<<c);j++)
                if (clc(i,j,0) && che(i,j,(1<<c)-1))
                    res=max(res,DP[r][i][j]);
        cout<<res<<endl;
    }
}