#include <bits/stdc++.h>

using namespace std;

bitset < 2020 > a[2020];
int n;

void gauss(){
	for (int i=1;i<=n;i++){
        int j=i;
        while (!a[j][i] && j <= n) j++;
        if (j <= n && j != i) swap(a[i],a[j]);
		for (int j=1;j<=n;j++)
		    if (i != j && a[j][i]) a[j] ^= a[i];
	}
}

int t,m,i,x,y;
int tot[2020];

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (i=1;i<=m;i++) {
            scanf("%d%d",&x,&y);
            a[x][y]=a[y][x]=1; tot[x]++; tot[y]++;
        }
        for (i=1;i<=n;i++)
            if (tot[i]%2) a[i][i]=a[i][n+1]=1;
        gauss();
        int ans=1;
        for (i=1;i<=n;i++)
            if (a[i][n+1]) ans=2;
        cout<<ans<<endl;
        for (i=1;i<=n;i++) {
            cout<<a[i][n+1]+1<<" ";
            a[i].reset(); tot[i]=0;
        }
        cout<<endl;
    }
}