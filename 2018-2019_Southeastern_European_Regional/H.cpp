#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 121;

int t;
int n, m;
int v[MAXN],u[MAXN],num[MAXN];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    srand(1181881);

    cin >> t;
    while(t-->0){
        cin >> n >> m;
        for(int i = 1; i <= m; ++i){
            cin >> v[i] >> u[i];
        }
        int need = m / 4 + 1;
        int cnt;
        while(1){
            for(int i = 1; i <= n; ++i){
                num[i] = rand() % 2;
            }
            cnt = 0;
            for(int j = 1; j <= m; ++j){
                cnt += (num[v[j]] && !num[u[j]]);
            }
            if(cnt >= need)break;
        }
        cout << cnt << '\n';
        for(int i = 1; i <= m; ++i){
            if(num[v[i]] && !num[u[i]]) cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}