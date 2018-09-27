#include <bits/stdc++.h>

using namespace std;

#define D double
#define PI 3.14159265359

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

double x[200],y[200],r;
int n;

void get(int i,double &xx,double &yy) {
    double AX=x[(j+n-1)%n];
    double AY=y[(j+n-1)%n];
    double BX=x[j];
    double By=y[j];
    double CX=x[(j+1)%n];
    double CY=y[(j+1)%n];
    double an=calc_angl(BX,BY,CX,CY)-calc_angl(BX,BY,AX,AY);
    if (an < 0) an*=-1;
    if (an > 180) ans=360-an;
    an/=2;
    double dst=r/sin(an*PI/180);
    an=calc_angl(BX,BY,AX,AY)+an;
    if (an > 360) an-=360;
    xx=BX+cos(an*PI/180)*dst;
    yy=BY+sin(an*PI/180)*dst;
}

int n,i,j;

int main() {
     cin>>n>>r;
     for (i=0;i<n;i++)
        cin>>x[i]>>y[i];
     for (j=0;j<n;j++)
        for (i=0;i<n;i++)
            if (j != i) {
                double FIX,FIY,SEX,SEY;
                get(j,FIX,FIY);
                get(i,SEX,SEY);
                cout<<FIX<<" "<<FIY<<" "<<SEX<<" "<<SEY<<" "<<i<<" "<<j<<endl;
            }
}