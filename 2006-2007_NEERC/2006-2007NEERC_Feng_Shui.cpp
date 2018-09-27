#include <bits/stdc++.h>

using namespace std;

#define D double
#define PI 3.14159265359

double triangle_area_2 (double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool clockwise (double x1, double y1, double x2, double y2, double x3, double y3) {
	return triangle_area_2 (x1, y1, x2, y2, x3, y3) <0 ;
}

D calc_angl(D x,D y,D X,D Y)
 {

  if (X == x)
   {
    if (Y > y) return 90; else
               return 270;
   }

  if (Y == y)
   {
    if (X > x) return 0; else
               return 180;
   }

  D d_Y=Y-y;
  if (d_Y < 0) d_Y*=(-1);

  D d_X=X-x;
  if (d_X < 0) d_X*=(-1);

  D hyp=sqrt(d_X*d_X+d_Y*d_Y);

  D alpha=asin(d_Y/hyp)*180/PI;

  if (X >= x && Y >= y) return alpha;
  if (X <= x && Y >= y) return 180-alpha;
  if (X <= x && Y <= y) return 180+alpha;
  if (X >= x && Y <= y) return 360-alpha;

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

double x[200],y[200],r;
int n;

bool get(int i,int j,double &xx,double &yy) {
    double AX=x[(i+1)%n];
    double AY=y[(i+1)%n];
    double BX=x[i];
    double BY=y[i];
    line nb;
    nb.a=BY-AY;
    nb.b=AX-BX;
    nb.c= -nb.a * BX - nb.b*BY;

    double CX=x[(j+1)%n];
    double CY=y[(j+1)%n];
    double DX=x[j];
    double DY=y[j];
    line m;
    m.a=DY-CY;
    m.b=CX-DX;
    m.c= -m.a * DX - m.b*DY;

    if (parallel(nb,m)) return false;

    pt res;
    intersect(nb,m,res);
    BX=res.x;
    BY=res.y;
    CX=x[i];
    CY=y[i];
    AX=x[(j+1)%n];
    AY=y[(j+1)%n];
    if (j == n-1 && i == 0) {
        AX=x[j];
        AY=y[j];
        CX=x[1];
        CY=y[1];
    }

    double an=calc_angl(BX,BY,CX,CY)-calc_angl(BX,BY,AX,AY);
    if (an < 0) an*=-1;
    if (an > 180) an=360-an;

    double che=calc_angl(BX,BY,AX,AY)+an;
    if (che >= 360) che-=360;
    if (che + 0.00001 < calc_angl(BX,BY,CX,CY) || calc_angl(BX,BY,CX,CY) + 0.00001 < che ) {
        swap(AX,CX);
        swap(AY,CY);
    }

    an/=2;
    double dst=r/sin(an*PI/180);
    an=calc_angl(BX,BY,AX,AY)+an;
    if (an >= 360) an-=360;
    xx=BX+cos(an*PI/180)*dst;
    yy=BY+sin(an*PI/180)*dst;
    return true;
}

int i,j;
double best=-1,ans1X,ans2X,ans1Y,ans2Y;
bool good[200][200];
double XX[200][200],YY[200][200];

int main() {
     cin>>n>>r;
     for (i=0;i<n;i++)
        cin>>x[i]>>y[i];
     for (i=0;i<n;i++)
        for (j=i+1;j<n;j++) {
                double FIX,FIY;
                if (!get(i,j,FIX,FIY))
                    continue;
                int c;
                for (c=0;c<n;c++) {
                    double aa=sqrt((FIX-x[c])*(FIX-x[c])+(FIY-y[c])*(FIY-y[c]));
                    double bb=sqrt((FIX-x[(c+1)%n])*(FIX-x[(c+1)%n])+(FIY-y[(c+1)%n])*(FIY-y[(c+1)%n]));
                    if (aa+0.00001 < r) break;
                    if (bb+0.00001 < r) break;
                    aa=sqrt(aa*aa-r*r);
                    bb=sqrt(bb*bb-r*r);

                    double cc=sqrt( (x[c]-x[(c+1)%n])*(x[c]-x[(c+1)%n])+(y[c]-y[(c+1)%n])*(y[c]-y[(c+1)%n]));
                    aa+=bb;
                    if (aa + 0.000001 < cc )break;
                }
                if (c != n) continue;

                for (c=0;c<n;c++)
                    if (!clockwise(x[c],y[c],x[(c+1)%n],y[(c+1)%n],FIX,FIY)) break; 
                if (c != n) continue;

                good[i][j]=true;
                XX[i][j]=FIX;
                YY[i][j]=FIY;
            }
    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
            for (int ii=0;ii<n;ii++)
                for (int jj=ii+1;jj<n;jj++)
                    if (good[i][j] && good[ii][jj]) {
                        double FIX=XX[i][j];
                        double FIY=YY[i][j];
                        double SEX=XX[ii][jj];
                        double SEY=YY[ii][jj];
                        if (((FIX-SEX)*(FIX-SEX)+(FIY-SEY)*(FIY-SEY)) > best) {
                            best=((FIX-SEX)*(FIX-SEX)+(FIY-SEY)*(FIY-SEY));
                            ans1X=FIX;
                            ans1Y=FIY;
                            ans2X=SEX;
                            ans2Y=SEY;
                         }
                    }
    printf("%.6f %.6f %.6f %.6f\n",ans1X,ans1Y,ans2X,ans2Y);
}