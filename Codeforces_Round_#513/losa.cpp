#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000

vector < int > vec[MAXN+20];
int ken[MAXN+20],lu[MAXN+20],n;
long long fi;

void calc(int from,int now) {

    vector < int > kent,luw;
    
    for (int to=0;to<vec[now].size();to++) {
        int next=vec[now][to];
        if (next != from) {
            calc(now,next);
            kent.push_back(ken[next]);
            luw.push_back(lu[next]);
            ken[now]+=lu[next];
            lu[now]+=ken[next];
        }
    }

    for (int to=0;to<luw.size();to++) {
        fi+=2LL*(n-luw[to]-kent[to])*(luw[to]+kent[to]);
        fi+=1LL*((lu[now]-kent[to])*luw[to]+(ken[now]-luw[to])*kent[to])+2*luw[to];
    }

    lu[now]++;
}

int main() {
    std::ios::sync_with_stdio(false);
    int u,v;
    cin>>n;
    for (int i=0;i+1<n;i++) {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    calc(-1,1);
    cout<<fi/4<<endl;
}