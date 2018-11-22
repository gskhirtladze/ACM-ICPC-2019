#include <bits/stdc++.h>

using namespace std;

int b,p,k,i,j;
int pos[1002],x[1002],a[1002];
vector < int > ans;
int main() {
    cin>>b;
    cin>>p;
    for (i=0;i<p;i++)
        cin>>x[i];
    cin>>k;
    for (j=0;j<k;j++)
        cin>>a[j]>>pos[j],pos[j]--;
    while (k) {
        int ad=0;
        for (j=k-1;j>=0;j--) {
            while (pos[j] < p-1 && (j == 0 || x[pos[j]+1]-x[pos[j-1]] <= b) && (j == k-1 || x[pos[j+1]]-x[pos[j]+1] >= max(a[j],a[j+1]) ) ) {
                ans.push_back(j);
                pos[j]++;
                ad++;
            }
            if (pos[j] == p-1) k--;
        }
        if (!ad) break;
    }
    if (k) {
        cout<<"impossible"<<endl;
        return 0;
    }
    for (int i=0;i<ans.size();i++)
        printf("%d ",ans[i]+1);
}