#include <bits/stdc++.h>

using namespace std;

int f(int x) {
    int ret=0;
    if (x == 0) return 1;
    while (x) {
        if (x%10 == 0) ret++;
        if (x%10 == 4) ret++;
        if (x%10 == 6) ret++;
        if (x%10 == 8) ret+=2;
        if (x%10 == 9) ret++;
        x/=10;
    }
    return ret;
}

int t;
int x,k;
bool mp[10];

int main() {
    scanf("%d",&t);
    while (t--) {
        scanf("%d%d",&x,&k);
        for (int i=0;i<10;i++)
            mp[i]=0;
        int tot=0;
        while (k) {
            tot=0;
            if (x < 10)
                mp[x]=1;
            x=f(x);
            if (x < 10 && mp[x]) break;
            k--;
            if (tot > 5) break;
        }
        if (k!=0)
            x^=(1^(k%2));
        printf("%d\n",x);
    }
}