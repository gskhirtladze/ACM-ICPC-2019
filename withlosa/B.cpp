#include <bits/stdc++.h>

using namespace std;

double x[102],y[102];
int n,i,j,k;
double res,ans;

double triangle_area_2 (double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool clockwise (double x1, double y1, double x2, double y2, double x3, double y3) {
	return triangle_area_2 (x1, y1, x2, y2, x3, y3) <= 0;
}
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

double dist(double x,double y,double X,double Y,double a,double b) {
    if (x == X) return abs(a-x);
    if (y == Y) return abs(b-y);
    double A=1;
    double B=(X-x)/(y-Y);
    double C=-A*x-B*y;
    double AA=-B;
    double BB=A;
    double CC=-AA*a-BB*b;
    line p1;
    line p2;
    p1.a=AA;
    p1.b=BB;
    p1.c=CC;
    p2.a=A;
    p2.b=B;
    p2.c=C;
    pt res;
    intersect(p1,p2,res);
    return sqrt((a-res.x)*(a-res.x)+(b-res.y)*(b-res.y));
}

int main() {
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    ans=2000000;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) if (i!= j){
            res=0;
            for (int k=1;k<=n;k++)
                if (!clockwise(x[i],y[i],x[j],y[j],x[k],y[k]))
                    res=2000000;
            for (int k=1;k<=n;k++) 
                res=max(res,dist(x[i],y[i],x[j],y[j],x[k],y[k]));
            ans=min(ans,res);
        
    }
    printf("%.9f\n",ans);
}