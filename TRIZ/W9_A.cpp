#include <iostream>
typedef long long ll;
using namespace std;

int t, x, n, m;

ll mpow(int e) {
	ll r = 1, b = x;
	while (e > 0) {
		if (e % 2) r = r * b % m;
		b = b * b % m;
		e = e / 2;
	}
	return r;
}

ll rec(int n) {
	if (n == 1) return (ll)x % m;
	return (rec(n / 2) * (1 + mpow(n / 2)) % m + (n % 2 ? mpow(n) : 0ll)) % m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> x >> n >> m;
		cout << rec(n) << '\n';
	}

	return 0;
}