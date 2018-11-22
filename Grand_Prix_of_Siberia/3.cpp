#include <bits/stdc++.h>
#define F first
#define S second
#define LL long long
#define mp make_pair
#define pb push_back
using namespace std;

LL h,w,k;
int mine[10005][16][30], xmin, ymin, fox[30][30], total[30][30], fix[10005];
bool ended = false;

void calc_min() {
    xmin = ymin = -1;
    for (int ii = 1; ii <= h; ii++)
        for (int jj = 1; jj <= w; jj++) {
            int i = ii%h;
            int j = jj%w;

            if (fox[i][j] == 1) continue;
            if (xmin == -1 || total[i][j] < total[xmin][ymin]) {
                xmin = i;
                ymin = j;
            }
        }
}

void prec() {
    for (LL s = 100; s <= 10000; s++) {
        LL t = s;
        for (int i = 0; i < k; i++) {
            t = (48271 * t) % 2147483647;
            if (mine[s][(t/w)%h][t%w]) {i--; continue;}
            mine[s][(t/w)%h][t%w]++;
            total[(t/w)%h][t%w]++;
        }
    }
}

int get_mines(int s) {
    if (mine[s][xmin][ymin] == 1) return -1;
    int ret = 0;

    for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++) {
            int nx = xmin + dx;
            int ny = ymin + dy;
            if (nx < 0 || ny < 0 || nx == h || ny == w) continue;
            ret += mine[s][nx][ny];
        }

    return ret;
}

void recalc(int x) {

    for (int s = 100; s <= 10000; s++) {
        if (fix[s] == 1) continue;
        if (get_mines(s) != x) {
            fix[s] = 1;
            for (int i = 0; i < h; i++)
                for (int  j = 0; j < w; j++)
                    total[i][j] -= mine[s][i][j];
        }
    }

}



void read_result() {
    string s;
    int x = -1;
    cin>>s;
    if (s == "Empty") cin>>x;
    if (s == "Win" || s == "Lose") {
        ended = true;
        return;
    }
    recalc(x);
}

int main() {

    cin>>h>>w>>k;
    prec();

    while(true) {
        calc_min();
        cout<<xmin<<" "<<ymin<<endl;
        fox[xmin][ymin] = 1;
        fflush(stdout);
        read_result();
        if (ended) return 0;
    }
}
