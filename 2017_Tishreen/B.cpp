#include <bits/stdc++.h>
using namespace std;
 
#ifndef max
  #define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
  #define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
 
class Point2d{
public:
    Point2d() {}
    Point2d(double x, double y)
        : X(x), Y(y) {}
     
    double x() const { return X; }
    double y() const { return Y; }
     
    double norm() const {
        return sqrt( X * X + Y * Y );
    }
     
    void setCoords(double x, double y) {
        X = x; Y = y;
    }
     
    // Print point
    friend std::ostream& operator << ( std::ostream& s, const Point2d& p )  {
      //s << p.x() << " " << p.y();
      return s;
    }
private:
    double X;
    double Y;
};
 
class Circle{
public:
    /**
     * @param R - radius
     * @param C - center
     */
    Circle(double R, Point2d& C) 
        : r(R), c(C) {}
         
    /**
     * @param R - radius
     * @param X - center's x coordinate
     * @param Y - center's y coordinate
     */
    Circle(double R, double X, double Y) 
        : r(R), c(X, Y) {}    
     
    Point2d getC() const { return c; }
    double getR() const { return r; }
     
    size_t intersect(const Circle& C2, Point2d& i1, Point2d& i2) {
        // distance between the centers
        double d = Point2d(c.x() - C2.c.x(), 
                c.y() - C2.c.y()).norm();
         
        // find number of solutions
        if(d > r + C2.r) // circles are too far apart, no solution(s)
        {
            //std::cout << "Circles are too far apart\n";
            return 0;
        }
        else if(d == 0 && r == C2.r) // circles coincide
        {
            //std::cout << "Circles coincide\n";
            return 0;
        }
        // one circle contains the other
        else if(d + min(r, C2.r) < max(r, C2.r))
        {
            //std::cout << "One circle contains the other\n";
            return 0;
        }
        else
        {
            double a = (r*r - C2.r*C2.r + d*d)/ (2.0*d);
            double h = sqrt(r*r - a*a);
             
            // find p2
            Point2d p2( c.x() + (a * (C2.c.x() - c.x())) / d,
                    c.y() + (a * (C2.c.y() - c.y())) / d);
             
            // find intersection points p3
            i1.setCoords( p2.x() + (h * (C2.c.y() - c.y())/ d),
                    p2.y() - (h * (C2.c.x() - c.x())/ d)
            );
            i2.setCoords( p2.x() - (h * (C2.c.y() - c.y())/ d),
                    p2.y() + (h * (C2.c.x() - c.x())/ d)
            );
             
            if(d == r + C2.r)
                return 1;
            return 2;
        }
    }
     
    // Print circle
    friend std::ostream& operator << ( std::ostream& s, const Circle& C )  {
      //s << "Center: " << C.getC() << ", r = " << C.getR();
      return s;
    }
private:
    // radius
    double r;
    // center
    Point2d c;
     
};

int t,n,m,i,j;
double x[200020];
double y[200020];
double r[200020];
int s[200020];


int main() {
    cin>>t;
    while (t--) {
        cin>>n>>m;
        vector < pair < double , double > > all;
        for (i=1;i<=n;i++)
            cin>>x[i]>>y[i]>>r[i]>>s[i],all.push_back({x[i],y[i]});
        for (i=1;i<=n;i++)
            for (j=i+1;j<=n;j++) {
                Circle c1(r[i], x[i], y[i]);
                Circle c2(r[j], x[j], y[j]);
                Point2d i1, i2;
                size_t i_points = c1.intersect(c2, i1, i2);
                if (i_points == 0)
                    continue;
                all.push_back({i1.x(),i1.y()});
                if (i_points == 2) {
                    all.push_back({i2.x(),i2.y()});
                }
            }
        int ret=0;
        for (j=0;j<all.size();j++) {
            vector < int > res;
            for (i=1;i<=n;i++)
                if (r[i]*r[i]+0.000001 >= (all[j].first-x[i])*(all[j].first-x[i])+(all[j].second-y[i])*(all[j].second-y[i]))
                    res.push_back(s[i]);
            sort(res.begin(),res.end());
            reverse(res.begin(),res.end());
            int now=0;
            for (i=0;i<min(res.size(),m);i++)
                now+=res[i];
            ret=max(ret,now);
        }
        cout<<ret<<endl;
    }
}