#include <bits/stdc++.h>
using namespace std;

double pdw[30];
long long pw[19];

int is(long long n, int a, int f) {
	if (n < 0) return 0;
	if (a == 1) {
		if (n >= 10) return 0;
		if (f && !n) return 0;
		return 1;
	}
	if (a == 0) {
		if (n) return 0;
		return 1;
	}
	int d = n % 10;
	if (f && !d) return 0;
	n -= (d + pw[a-1] * d);
	n /= 10;
	return is(n, a-2, 0);
}

int calc(long long n, int a, int b, int f) {
	if (n < 0) return 0;
	if (n >= pdw[a] * 1.2) return 0;
	long long p = n / pw[a-1];
	if (!p && f) return 0;
	if (b == 1) {
		int ret = 0;
		for (int i = f; i <= 9; i++) {
			ret += is(n - i, a, f);
		}
		return ret;
	}
	if (b == 0) return is(n, a, f);
	int ret = 0;
	for (int q : {p, p-1}) {
		if (q < 0) continue;
		if (q >= 10) continue;
		if (!q && f) continue;
		long long m = n - pw[a-1] * q - q;
		if (m < 0) continue;
		int dig = m % 10;
		if (f && !dig) continue;
		m -= (dig + pw[b-1] * dig);
		assert(m % 10 == 0);
		m /= 10;
		ret += calc(m, a-2, b-2, 0);
	}
	return ret;
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
	for (int x : {k, k-1, k-2}) {
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

int is(long long n) {
	for (int i = 0; i < 19; i++) if (is(n, i, 1)) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	long long n; cin >> n;
	long long ans = 0;
	pw[0] = pdw[0] = 1;
	for (int i = 1; i < 19; i++) pw[i] = pw[i-1] * 10;
	for (int i = 1; i < 30; i++) pdw[i] = pdw[i-1] * 10;
	for (int i = 0; i <= 18; i++) {
		ans += calc(n, i, 1);
	}
    cout<<ans<<endl;
	for (int i = 1; i <= 18; i++) {
		for (int j = 0; j < i; j++) {
			ans += 2 * calc(n, i, j, 1);
		}
	}
    cout<<ans<<endl;
	if (is(n)) ans -= 2;
	cout << ans << endl;
	return 0;
}