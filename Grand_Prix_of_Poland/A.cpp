#include <bits/stdc++.h>

using namespace std;

struct pt {
	double x, y;
};
 
struct line {
	double a, b, c;
};
 
const double EPS = 1e-9;
 
double det (double a, double b, double c, double d) {
	return a * d - b * c;
}
 
bool intersect (line m, line n, pt & res) {
	double zn = det (m.a, m.b, n.a, n.b);
	if (abs (zn) < EPS)
		return false;
	res.x = - det (m.c, m.b, n.c, n.b) / zn;
	res.y = - det (m.a, m.c, n.a, n.c) / zn;
	return true;
}
 
bool parallel (line m, line n) {
	return abs (det (m.a, m.b, n.a, n.b)) < EPS;
}
 
bool equivalent (line m, line n) {
	return abs (det (m.a, m.b, n.a, n.b)) < EPS
		&& abs (det (m.a, m.c, n.a, n.c)) < EPS
		&& abs (det (m.b, m.c, n.b, n.c)) < EPS;
}

line mline(double a,double b,double c) {
    line x;
    x.a=a;
    x.b=b;
    x.c=c;
    return x;
}

double a,b,c,A,B,C;
double ans;

int main() {
    cin>>a>>b>>c;
    cin>>A>>B>>C;
    pt a1,a2,a3,a4,a5;
    bool x=intersect(mline(a,b,c),mline(A,B,C),a5);
    if (x)
        ans=2*sqrt(a5.x*a5.x+a5.y*a5.y); else
        ans=1000000000;
        
    intersect(mline(a,b,c),mline(-b,a,0),a1);
    a4=a1;
    bool y=intersect(mline(A,B,C),mline(-b,a,0),a2);
    if (y && (a1.x*a2.x >= 0 && a1.y*a2.y >= 0))
        ans=min(ans,max(sqrt(a1.x*a1.x+a1.y*a1.y),sqrt(a2.x*a2.x+a2.y*a2.y)));

    intersect(mline(A,B,C),mline(-B,A,0),a1);
    y=intersect(mline(a,b,c),mline(-B,A,0),a2);
    if (y && (a1.x*a2.x >= 0 && a1.y*a2.y >= 0))
        ans=min(ans,max(sqrt(a1.x*a1.x+a1.y*a1.y),sqrt(a2.x*a2.x+a2.y*a2.y)));
    if (!x) {
        printf("%.9f\n",ans);
        return 0;
    }
    if (a4.x*a4.x+a4.y*a4.y+a1.x*a1.x+a1.y*a1.y >= (a4.x-a1.x)*(a4.x-a1.x)+(a4.y=a1.y)*(a4.y-a1.y)) {
        printf("%.9f\n",ans);
        return 0;
    }

    pt res;
    x=intersect(mline(a,b,c),mline(-b,a,0),res);
    res.x*=-1; res.y*=-1;
    res.x*=2;
    res.y*=2;
    pt res2;
    intersect(mline(A,B,C),mline(B,-A,B*res.x-A*res.y),res2);
    res2.x*=-1; res2.y*=-1;
    res2.x=res2.x*2-res.x;
    res2.y=res2.y*2-res.y;

    ans=min(ans,max(sqrt(res.x*res.x+res.y*res.y),sqrt(res2.x*res2.x+res2.y*res2.y)));
    swap(a,A); swap(b,B); swap(c,C);
    intersect(mline(a,b,c),mline(b,-a,0),res);
    res.x*=2;
    res.y*=2;
    intersect(mline(A,B,C),mline(B,-A,B*res.x-A*res.y),res2);
    res2.x=res2.x*2-res.x;
    res2.y=res2.y*2-res.y;
    ans=min(ans,max(sqrt(res.x*res.x+res.y*res.y),sqrt(res2.x*res2.x+res2.y*res2.y)));
    printf("%.9f\n",ans);

}