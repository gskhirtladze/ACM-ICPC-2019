#include <bits/stdc++.h>

using namespace std;

int a,b,c,x,y,z,A,B,C,X,Y,Z;
void pt() {
    cout<<"( "<<a<<" "<<b<<" "<<c<<" ) ( "<<x<<" "<<y<<" "<<z<<" )"<<endl;
}
int main() {
    cin>>a>>b>>c>>A>>B>>C;
    cin>>x>>y>>z>>X>>Y>>Z;
    pt();
    if (a == x) a++,pt();
    if (b == y) b++,pt();
    if (c == z) c++,pt();
    if (A != X) {
        while (a < A) a++,pt();
        while (a > A) a--,pt();
        while (x < X) x++,pt();
        while (x > X) x--,pt(); 
    }
    if (B != Y) {
        while (b < B) b++,pt();
        while (b > B) b--,pt();
        while (y < Y) y++,pt();
        while (y > Y) y--,pt(); 
    }
    if (C != Z) {
        while (c < C) c++,pt();
        while (c > C) c--,pt();
        while (z < Z) z++,pt();
        while (z > Z) z--,pt(); 
    }

        while (a < A) a++,pt();
        while (a > A) a--,pt();
        while (x < X) x++,pt();
        while (x > X) x--,pt(); 
        while (b < B) b++,pt();
        while (b > B) b--,pt();
        while (y < Y) y++,pt();
        while (y > Y) y--,pt(); 
        while (c < C) c++,pt();
        while (c > C) c--,pt();
        while (z < Z) z++,pt();
        while (z > Z) z--,pt(); 
}
