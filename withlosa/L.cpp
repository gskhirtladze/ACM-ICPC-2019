#include <bits/stdc++.h>
using namespace std;	
double tx, ty;
bool cmp(pair < pair < int, int >, int > p1, pair < pair < int, int >, int > p2){
	double dist1 = 1LL*(p1.first.first-tx)*(p1.first.first-tx) + 1LL*(p1.first.second-ty)*(p1.first.second-ty);
	double dist2 = 1LL*(p2.first.first-tx)*(p2.first.first-tx) + 1LL*(p2.first.second-ty)*(p2.first.second-ty);
	return dist1<dist2;
}
int tree[1000001];
int MAXX(int ind)
{
	int res=0;
	for(;ind>=0;ind=(ind&(ind+1))-1)
	  res=max(res,tree[ind]);
	return res;
}
void update(int ind,int vol)
{
	for(;ind<=1000000;ind=(ind|(ind+1)))
 	  tree[ind]=max(tree[ind],vol);
}
void upd0(int ind)
{
	for(;ind<=1000000;ind=(ind|(ind+1)))
 	  tree[ind]=0;
}
int main(){
	
	cin>>tx>>ty;
	map < pair < pair < int , int > , int > , bool > fix;
	map < pair < pair < int , int >, int > , vector < int > > vec;
	vector < pair < pair < int , int > , int > > g;
	int n;
	cin>>n;
	pair < pair < int, int > , int > p[n+1];
	for(int i=0;i<n;i++){
				 scanf("%d%d%d",&p[i].first.first,&p[i].first.second,&p[i].second);
	}
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++){
		int x = p[i].first.first;
		int y = p[i].first.second;
		x-=tx;
		y-=ty;
		pair < int , int > bla;
		int Z; {
			bla = { abs(x)/__gcd(abs(x),abs(y)) , abs(y)/__gcd(abs(x),abs(y))};
			if(x>=0 && y>=0)Z = 1;
			if(x>=0 && y<0)Z = 4;
			if(x<0 && y>=0)Z = 2;
			if(x<0 && y<0)Z = 3;
		}
		if(!fix[{bla,Z}]){
			fix[{bla,Z}]=1;
			g.push_back({bla,Z});
		}
		vec[{bla,Z}].push_back(p[i].second);
	}
	int ans = 0;
	for(int i=0;i<g.size();i++){
		int dp[vec[g[i]].size()+1];
		dp[1]=1;
		update(vec[g[i]][0],1);
		int maxx=1;
		for(int j=1;j<vec[g[i]].size();j++){
			int to = vec[g[i]][j];
			dp[j]=MAXX(to-1)+1;
			update(to,dp[j]);
			maxx = max(maxx,dp[j]);
		}
		for(int j=0;j<vec[g[i]].size();j++){
			int to = vec[g[i]][j];
			upd0(to);
		}
		ans += maxx;
		
	}
	cout<<ans<<endl;
	return 0;
}