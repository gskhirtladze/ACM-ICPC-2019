#include <bits/stdc++.h>

using namespace std;

long long l,c,n,p,x,a,b,i,j,s;
long long A[200020];
int rao[342][100020];
vector < int > all[342];
int cl[342];
int Q,mx;
int tot[200020];

void calc() {
    for (int i=0;i<mx;i++) {
        for (int j=0;j<all[i].size();j++)
            if (cl[i]) tot[cl[i]]++; else tot[all[i][j]]++;
    }
    for (int i=1;i<=c;i++)
        tot[i]=max(tot[i],tot[i-1]);
    cout<<tot[c]<<endl;
}

int main() {
    cin>>l>>c>>n;
    Q=317;
    mx=(l-1)/Q+1;
    for (i=0;i<l;i++)
        all[i/Q].push_back(1);
    for (i=0;i<mx;i++)
        rao[i][1]=all[i].size();

    while (n--) {
        scanf("%d%d%d%d",&p,&x,&a,&b);
        s=0;
        for (j=0;j<mx;j++) {
            if (cl[j]) {
                if (cl[j] == p)
                    s+=all[j].size();
            } else s+=rao[j][p];
        }
        int m1=(a+(1LL*s*s)%l)%l;
        int m2=(a+(1LL*((s+b)%l)*((s+b)%l)))%l;
        if (m1 > m2) swap(m1,m2);
        if (m1/Q == m2/Q) {
            for (j=0;j<all[m1/Q].size();j++) {
                rao[m1/Q][all[m1/Q][j]]--;
                if (cl[m1/Q])
                    all[m1/Q][j]=cl[m1/Q];
                if (j >= m1%Q && j <= m2%Q)
                    all[m1/Q][j]=x;
                rao[m1/Q][all[m1/Q][j]]++;
            }
            cl[m1/Q]=0;
            continue;
        }
        for (j=m1/Q+1;j<=m2/Q-1;j++)
            cl[j]=x;
        for (j=0;j<all[m1/Q].size();j++) {
            rao[m1/Q][all[m1/Q][j]]--;
            if (cl[m1/Q])
                all[m1/Q][j]=cl[m1/Q];
            if (j >= m1%Q)
                all[m1/Q][j]=x;
            rao[m1/Q][all[m1/Q][j]]++;
        }
        cl[m1/Q]=0;
        for (j=0;j<all[m2/Q].size();j++) {
            rao[m2/Q][all[m2/Q][j]]--;
            if (cl[m2/Q])
                all[m2/Q][j]=cl[m2/Q];
            if (j <= m2%Q)
                all[m2/Q][j]=x;
            rao[m2/Q][all[m2/Q][j]]++;
        }
        cl[m2/Q]=0;
    }
    calc();
}