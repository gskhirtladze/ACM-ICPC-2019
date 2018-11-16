#include <bits/stdc++.h>

#define PI 3.14159265

using namespace std;

double triangle_area_2 (double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

bool clockwise (double x1, double y1, double x2, double y2, double x3, double y3) {
	return triangle_area_2 (x1, y1, x2, y2, x3, y3) < 0;
}

char get(){
    string s;
    double a,b,x,y;
    int X,Y;
    char ans;
    cin>>s>>a>>b;
    if (s == "CD") a+=60;
    if (s == "DB") a+=120;
    x=b*cos(a*PI/180);
    y=b*sin(a*PI/180);
    while (y < 0) y+=4*sqrt(3)/2;
    while (y >= 4*sqrt(3)/2) y-=4*sqrt(3)/2;
    Y=int(y/(sqrt(3)/2));

    if (Y >= 2) {
        Y-=2;
        y-=2*sqrt(3)/2;
        x--;
    }

    while (x < 0) x+=2;
    while (x >= 2) x-=2;
    X=int(x);

    if (Y == 0) {
        if (X == 0) {
            if (!clockwise(0,0,0.5,sqrt(3)/2,x,y)) ans='B'; else
            if (clockwise(1,0,0.5,sqrt(3)/2,x,y)) ans='A'; else
            ans='D';
        }
        if (X == 1) {
            if (!clockwise(1,0,1.5,sqrt(3)/2,x,y)) ans='A'; else
            if (clockwise(2,0,1.5,sqrt(3)/2,x,y)) ans='B'; else
            ans='C';
        }
    }

    if (Y == 1) {
        if (X == 0) {
            if (!clockwise(0.5,sqrt(3)/2,0,sqrt(3),x,y)) ans='A'; else
            if (clockwise(0.5,sqrt(3)/2,1,sqrt(3),x,y)) ans='B'; else
            ans='D';
        }
        if (X == 1) {
            if (!clockwise(1.5,sqrt(3)/2,1,sqrt(3),x,y)) ans='B'; else
            if (clockwise(1.5,sqrt(3)/2,2,sqrt(3),x,y)) ans='A'; else
            ans='C';
        }
    }
    return ans;
}

int main() {
    cout<<( (get()==get()) ? "YES" : "NO" )<<endl;
}