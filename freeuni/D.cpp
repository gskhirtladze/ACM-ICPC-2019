#include <bits/stdc++.h>

using namespace std;

vector < int > pr;
int lp[200020];
int A[200020];
int B[200020];
int i,j;

int n;

void add(int a,int b) {
    A[i]=a; B[i]=b;
}

int x,X,k,a;
map < int , int > rao;

int main() {
    for (i=2;i<=3162;i++) {
        if (lp[i] == 0) {
            pr.push_back(i);
            lp[i]=i;
        }
        for (int j=0;j<pr.size() && pr[j] <= lp[i] && pr[j]*i <= 3162;j++)
            lp[pr[j]*i]=pr[j];
    }
    cin>>n;
    for (i=1;i<=n;i++) {
        scanf("%d",&x);
        vector < pair < int , int > > all;
        X=x;
        for (int j=0;j<pr.size() && pr[j]*pr[j] <= X;j++) {
            if (x%pr[j] == 0) {
                int now=0;
                while (x%pr[j] == 0) {
                    now++;
                    x/=pr[j];
                }
                all.push_back({pr[j],now+1});
            }
        }
        if (x != 1)
            all.push_back({x,1+1});
        k=rao[X]++;
        a=1;
        for (int j=all.size()-1;j>=0;j--) {
            for (int ii=0;ii<k%all[j].second;ii++)
                a*=all[j].first;
            k/=all[j].second;
        }
        if (k != 0) {
            cout<<"NO"<<endl;
            return 0;
        }
        add(a,X/a);
    }
    cout<<"YES"<<endl;
    for (i=1;i<=n;i++)
        printf("%d %d\n",A[i],B[i]);
}