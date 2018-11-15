#include <bits/stdc++.h>

using namespace std;

double MI[1024];
double MA[1024];
bool f[1024];

void solve(int x) {
    if (f[x]) return;
    f[x]=1;
    if (x == 0) return;
    for (int j=1;j<=6;j++)
        for (int k=1;k<=6;k++) {
            double nowmi=-1,nowma=-1;
            for (int bi=0;bi<(1<<9);bi++)
                if ((x&bi) == bi) {
                    int now=0;
                    for (int l=0;l<9;l++)
                        if ((1<<l)&bi) now+=l+1;
                    if (now == j+k) {
                        solve(x-bi);
                        if (nowmi == -1 || nowmi > MI[x-bi])
                            nowmi=MI[x-bi];
                        if (nowma == -1 || nowma < MA[x-bi])
                            nowma=MA[x-bi];
                    }
                }
            if (nowmi == -1) {
                nowmi=0;
                for (int l=0;l<9;l++)
                    if (x&(1<<l)) nowmi=nowmi*10+l+1;
                nowma=nowmi;
            }
            MI[x]+=1.0*nowmi/36;
            MA[x]+=1.0*nowma/36;
        }
}

string s;
int x,j,k;
int resmi,resma;

int main() {
    cin>>s>>j>>k;
    for (int l=0;l<s.size();l++)
        x+=(1<<(s[l]-'1'));
    
    double nowmi=-1,nowma=-1;
    for (int bi=0;bi<(1<<9);bi++)
        if ((x&bi) == bi) {
            int now=0;
            for (int l=0;l<9;l++)
                if ((1<<l)&bi) now+=l+1;
            if (now == j+k) {
                solve(x-bi);
                if (nowmi == -1 || nowmi > MI[x-bi]) {
                    nowmi=MI[x-bi];
                    resmi=bi;
                }
                if (nowma == -1 || nowma < MA[x-bi]) {
                    resma=bi;
                    nowma=MA[x-bi];
                }
            }
        }
    if (nowmi == -1) {
        nowmi=0;
        for (int l=0;l<9;l++)
            if (x&(1<<l)) nowmi=nowmi*10+l+1;
        nowma=nowmi;
        resmi=-1;
        resma=-1;
    }

    if (resmi == -1) {
        printf("-1 %.5f\n-1 %.5f\n",nowmi,nowmi);
        return 0;
    }
    for (int l=0;l<9;l++)
        if (resmi&(1<<l))
            cout<<l+1;
    printf(" %.5f\n",nowmi);
    for (int l=0;l<9;l++)
        if (resma&(1<<l))
            cout<<l+1;
    printf(" %.5f\n",nowma);
}