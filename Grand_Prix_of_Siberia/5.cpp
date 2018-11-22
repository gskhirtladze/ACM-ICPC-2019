#include <bits/stdc++.h>

using namespace std;

string s[2002];
int f[2002];
vector < int > all[2002];
vector < int > g[2002];
vector < int > ind;
int rao,tot;
int us[2002];
int slv[2002];
int n;

void solve(int p,int u) {
    for (int i=0;i<all[u].size();i++)
        slv[all[u][i]]=1;

    for (int i=0;i<all[u].size();i++) {
        int to=all[u][i];
        for (int j=0;j<g[to].size();j++)
            if (!slv[g[to][j]])
                all[rao+1].push_back(g[to][j]);
    }

    if (all[rao+1].size() > 0) {
        int now=u;
        rao++;
        solve(u,rao);
    }
}

int node;
int nod[2002];

int rrao;
void dfs(int u) {
    if (f[u]) return;
    rrao++;
    nod[rrao]=u;
    f[u]=1;
    for (int i=0;i<g[u].size();i++)
        dfs(g[u][i]);
}

int k,i,j;
int d[2002][2002];
int D[2002];

int main() {
     srand (time(NULL));
    cin>>n>>k;
    for (i=0;i<n;i++) {
        getchar();
        for (j=0;j<n;j++)
            if (getchar() == '1') {
                g[i].push_back(j);
                d[i][j]=1;
             } else d[i][j]=9999;
        d[i][i]=0;
    }

    for (int k=0; k<n; ++k)
	    for (int i=0; i<n; ++i)
		    for (int j=0; j<n; ++j)
			    d[i][j] = (d[i][k] + d[k][j] < d[i][j]) ? d[i][k]+d[k][j] : d[i][j];

    for (int k=0;k<n;k++) {
        for (int j=0;j<n;j++)
            if (d[k][j] != 9999)
                D[k]=max(D[k],d[k][j]);
    }
    for (i=0;i<n;i++)
        if (f[i] == 0) {
            rrao=0;
            node=i;
            dfs(i);

            int bst=-1;
            for (int j=1;j<=rrao;j++)
                    if (bst < D[nod[j]]) {
                        bst=D[nod[j]];
                        node=nod[j];
                    }
                    
            ++rao;
            all[rao].push_back(node);

            solve(0,rao);
        }
    
    if (rao < k) {
        cout<<"Nope"<<endl;
        return 0;
    }
    cout<<"Yep"<<endl;
    int sum=n;
    for (i=1;i<=k-1;i++) {
        sum-=all[i].size();
        printf("%d",(int)all[i].size());
        sort(all[i].begin(),all[i].end());
        for (int j=0;j<all[i].size();j++)
            printf(" %d",all[i][j]+1);
        printf("\n");
    }
    printf("%d",sum);
    for (i=k;i<=rao;i++) {
        sort(all[i].begin(),all[i].end());
        for (int j=0;j<all[i].size();j++)
            printf(" %d",all[i][j]+1);
    }
    printf("\n");
}