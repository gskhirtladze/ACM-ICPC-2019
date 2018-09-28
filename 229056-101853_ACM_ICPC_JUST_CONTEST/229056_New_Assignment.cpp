#include <bits/stdc++.h>

using namespace std;

vector < int > mt,tt;
vector < bool > used;
char ch[20020];
int a[20020];
int ind[20020];
vector < int > all;
vector < int > g[20020];
int f[2000020];

bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
            tt[v] = to;
			return true;
		}
	}
	return false;
}

void add(int a,int b) {
    if (f[a] == 0) {
        all.push_back(a);
        f[a]=b;
        return;
    }
    a=f[a];
    if (ch[a] == 'M') swap(a,b);
    
    g[ind[a]-1].push_back(ind[b]-1);
}

int GB,i,j,n,m;

int main() {
    int t;
    cin>>t;
    while (t--) {
    mt.clear();
    tt.clear();
    used.clear();
    n=m=0;
    scanf("%d",&GB);
    for (i=1;i<=GB;i++) 
        scanf("%d",&a[i]);
    for (i=1;i<=GB;i++) {
        scanf(" %c",&ch[i]);
        if (ch[i] == 'F') { n++; ind[i]=n; }
        if (ch[i] == 'M') { m++; ind[i]=m; }
    }
    for (i=0;i<=n;i++) g[i].clear();
    for (i=0;i<all.size();i++)
        f[all[i]]=0;
    for (i=1;i<=GB;i++) {
        int x=a[i];
        for (j=2;j*j<=a[i];j++) {
            if (x%j == 0) {
                while (x%j == 0) x/=j;
                add(j,i);
            }
        }
        if (x != 1)
            add(x,i);
    }
    
    for (i=0;i<m;i++)
        mt.push_back(0);
    for (i=0;i<n;i++)
        tt.push_back(0),used.push_back(0);
    
    fill(mt.begin(),mt.end(),-1);
    fill(tt.begin(),tt.end(),-1);
    
    for (int run = 1; run; ) {
    run = 0; fill(used.begin(),used.end(), 0);
    for (i=0;i<n;i++)
        if (tt[i] == -1 && try_kuhn(i))
        run = 1;
    }
    int res=0;
	for (int i=0; i<m; ++i)
		if (mt[i] != -1)
			res++;
    cout<<GB-res<<endl;
    }
}
