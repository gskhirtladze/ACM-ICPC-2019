#include <bits/stdc++.h>

using namespace std;

int a[10000020];
int n,k,i;
set < vector < int > > st,st2;

int main() {
    cin>>n>>k;
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (i=1;i<=n;i++) {
        vector < int > now;
        for (int j=i;j<min(i+k,n+1);j++)
            now.push_back(a[j]);
        st.insert(now);
        if (st.size() > k)
            st.erase(*st.rbegin());
    }
    while (st.size()) {
        vector < int > now=*st.begin();
        st.erase(st.begin());
        vector < int > now2;
        for (int i=0;i<now.size();i++) {
            now2.push_back(now[i]);
            st2.insert(now2);
        }
    }
    if (st2.size() < k) {
        cout<<-1<<endl;
        return 0;
    }
    for (i=1;i<k;i++)
        st2.erase(st2.begin());
    vector < int > now=*st2.begin();
    for (int i=0;i<now.size();i++)
        cout<<now[i]<<" ";

}