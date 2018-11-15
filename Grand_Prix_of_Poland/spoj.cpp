#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T,N,i,x,y;
    pair<int,int> A[500002];
    scanf("%d",&N);
    for (i=0; i<N; i++)
    {
        scanf("%d %d",&x,&y); swap(x,y);
        A[i]=make_pair(x-y,x+y);
    }
    sort(A,A+N);
    set<int> S;
    for (i=0; i<N; i++)
    {
        set<int>::iterator It=S.upper_bound(A[i].second);
        if (It!=S.begin())
        {
            It--;
            S.erase(It);
        }
        S.insert(A[i].second);
    }
    printf("%d\n",(int)S.size());
	
	return 0;
}