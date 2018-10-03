#include <bits/stdc++.h>

using namespace std;

int t,n,i,j;
int a[505][505];
int now[505];
int lst[505];
int L[505];
int R[505];

int calc() {
    long long ret=0;
    int l=0;
    lst[0]=0;
    for (int i=1;i<=n;i++) {
        while (l > 0 && now[lst[l]] < now[i]) l--;
        L[i]=lst[l];
        lst[++l]=i;
    }
    lst[0]=n+1;
    l=0;
    for (int i=n;i>=1;i--) {
        while (l > 0 && now[lst[l]] <= now[i]) l--;
        R[i]=lst[l];
        lst[++l]=i;
    }
    for (int i=1;i<=n;i++)
        ret+=1LL*(i-L[i])*(R[i]-i)*now[i];
    return ret;
}

long long get_ans() {
    long long ret=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++)
            now[j]=a[j][i];
        ret+=calc();
        for (int k=i+1;k<=n;k++) {
            for (int j=1;j<=n;j++)
                now[j]=max(now[j],a[j][k]);
            ret+=calc();
        }
    }
    return ret;
}

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        long long A=get_ans();
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                a[i][j]*=-1;
        long long B=get_ans();
        cout<<A+B<<endl;
    }
}