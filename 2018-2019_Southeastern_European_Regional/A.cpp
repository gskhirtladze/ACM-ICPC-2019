#include <bits/stdc++.h>

using namespace std;

int res;
long long pw[34];

void check(long long n,int a,int f) {
    if (n < 0) return;
    if (n%10 == 0 && f) return;
    if (a == 1) {
        res+=(n<10);
        return;
    }
    if (a == 0) {
        res+=(n==0);
        return;
    }
    int di=n%10;
    if (n >= pw[a-1]*di+di)
        check((n-pw[a-1]*di-di)/10,a-2,0);
}

void solve(long long n,int a,int b,int f) {
    if (n < 0) return;
    long long fi=n/pw[a-1];
    if (fi>12) return;
    long long se=n%10;
    if (b == 0) {
        check(n,a,f);
        return;
    }
    if (b == 1) {
        for (int j=f;j<=9;j++) 
            check(n-j,a,f);
        return;
    }
    for (int di=fi-1;di<=fi;di++) {
        if (f && !di) continue;
        if (di > 9) continue;
        if (di < 0) continue;
        int de=(se-di+10)%10;
        if (f && !de) continue;
        if (n >= pw[a-1]*di+di+pw[b-1]*de+de)
            solve((n-pw[a-1]*di-di-pw[b-1]*de-de)/10,a-2,b-2,0);
    }
}

long long calc(long long n, int a, int f) {
	if (n < 0) return 0;
	if (a == 1) {
		int ret = 0;
		for (int i = f; i <= 9; i++) {
			if (f <= n - i && n - i <= 9) ret++;
		}
		return ret;
	}
	if (a == 0) {
		if (n == 0) return 1;
		return 0;
	}
	int d = n % 10;
	long long k = n / (pw[a-1] + 1);
	if (k > 20) return 0;
	long long ret = 0;
    for (int x=k-2;x<=k;x++) {
		if (x < 0 || x % 10 != d) continue;
		long long m = n - (pw[a-1] + 1) * x;
		long long cc = calc(m / 10, a-2, 0);
		int cnt = 0;
		for (int i = f; i <= 9; i++) {
			if (f <= x - i && x - i <= 9) cnt++;
		}
		ret += cnt * cc;
	}
	return ret;
}

long long n,i,j;

int main() {
    pw[0]=1;
    for (i=1;i<=18;i++)
        pw[i]=pw[i-1]*10;
    cin>>n;
    for (i=1;i<=18;i++)
        for (j=0;j<i;j++)
            solve(n,i,j,1);
   {
        res*=-1;
        for (i=0;i<=18;i++)
            check(n,i,1);
        res*=-1;
    }
    res*=2;
    for (i=0;i<=18;i++)
        res+=calc(n,i,1);
    cout<<res<<endl;
}