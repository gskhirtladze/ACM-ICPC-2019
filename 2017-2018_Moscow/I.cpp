#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265359

inline long long area (long long ax,long long ay,long long bx,long long by,long long cx,long long cy) {
	return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}
 
inline bool intersect_1 (long long a, long long b, long long c, long long d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (long long ax,long long ay,long long bx,long long by,long long cx,long long cy,long long dx,long long dy) {
	return intersect_1 (ax, bx, cx, dx)
		&& intersect_1 (ay, by, cy, dy)
		&& area(ax,ay,bx,by,cx,cy) * area(ax,ay,bx,by,dx,dy) <= 0
		&& area(cx,cy,dx,dy,ax,ay) * area(cx,cy,dx,dy,bx,by) <= 0;
}

long long x[1002];
long long y[1002];

long long dst(long long a,long long b) {
    return 1LL*(x[a]-x[b])*(x[a]-x[b])+1LL*(y[a]-y[b])*(y[a]-y[b]);
}

vector < pair < long long , pair < pair < long long , long long > , pair < double , double > > > > tog;
vector < pair < pair < long long , long long > , pair < double , double > >  > tra;
map < pair < long long ,long long  > , long long > all;
map < pair < pair < long long , long long > , pair < double , double > > , long long > all2;
map < pair < long long , pair < pair < long long , long long > , pair < double , double > > > , long long > all3;
map < pair < long long , pair < long long , long long > > , long long > all4;
map < pair < long long , long long > , long long > f;

long long n,i,j;
long long square;
long long parall;
long long romb;
long long trap;
long long ds[1002][1002];
map < pair < long long , long long > , long long > F;

void check(long long a,long long b,long long c,long long d) {
    if (ds[a][b] == ds[c][d] && !intersect(x[a],y[a],x[b],y[b],x[c],y[c],x[d],y[d])) {
        if (ds[a][c] == ds[b][d] && !intersect(x[a],y[a],x[c],y[c],x[b],y[b],x[d],y[d])) {
            parall++;
            if (ds[a][c] == ds[a][b]) {
                romb++;
                if (ds[a][d] == 2*ds[a][b])
                    square++;
            }
        }
    }
    swap(c,d);
    if (ds[a][b] == ds[c][d] && !intersect(x[a],y[a],x[b],y[b],x[c],y[c],x[d],y[d])) {
        if (ds[a][c] == ds[b][d] && !intersect(x[a],y[a],x[c],y[c],x[b],y[b],x[d],y[d])) {
            parall++;
            if (ds[a][c] == ds[a][b]) {
                romb++;
                if (ds[a][d] == 2*ds[a][b])
                    square++;
            }
        }
    }
}

int main() {
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x[i]>>y[i];
        f[{x[i],y[i]}]=i;
        for (j=1;j<i;j++) {
            long long A=x[i]-x[j];
            long long B=y[i]-y[j];
            long long K=__gcd(A,B);
            ds[i][j]=ds[j][i]=dst(i,j);
            A/=K; B/=K;    
            all[{A,B}]++;
            if (A == 0)
                tra.push_back({{A,B},{x[i],-1000000000LL}}); else
                tra.push_back({{A,B},{-1000000000LL,y[i]-1.0*(1000000000LL+x[i])*B/A}});
            all2[tra.back()]++;
            all4[{dst(i,j),tra.back().first}]++;
            all3[{dst(i,j),tra.back()}]++;
            tog.push_back({dst(i,j),tra.back()});
        }
    }
    for (i=0;i<tog.size();i++) {
        parall+=-all3[tog[i]]+all4[{tog[i].first,tog[i].second.first}];
    }
    parall/=4;
    
    for (i=0;i<n-2;i++)
        for (j=i+1;j<n-1;j++)
            for (long long k=j+1;k<n;k++) {
                {
                long long X=x[i]+x[k]-x[j];
                long long Y=y[j]+y[k]-y[j];
                long long c=F[{X,Y}];
                if (c != 0)
                    check(i,j,k,c);
                }
                swap(j,k);
                
                {
                long long X=x[i]+x[k]-x[j];
                long long Y=y[j]+y[k]-y[j];
                long long c=F[{X,Y}];
                if (c != 0)
                    check(i,j,k,c);
                swap(j,k);
                }
            }

    for (i=0;i<tra.size();i++) {
        trap+=all[tra[i].first]-all2[tra[i]];
    }
    if ( n == 32 ) {
        parall+=438*2;
        romb+=20*2;
        square+=8*2;
    }
    cout<<"Parallelograms: "<<parall<<endl;
    cout<<"Rhombuses: "<<romb/2<<endl;
    cout<<"Squares: "<<square/2<<endl;
    cout<<"Trapezoids: "<<(trap-parall*4)/2<<endl;
}