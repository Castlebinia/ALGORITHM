#include <iostream>
using namespace std;

typedef long long ll;

ll a[200000];
int n, k;
bool p = false;

bool foo(ll x) {
	ll ret = 0;
	for (int i = 0; i < n; i++) {
		if (x >= a[i])ret++;
	}
	if (ret == k)p = true;
	return k <= ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll l = 1;
	ll r = 10000000;
	ll ret = r;
	while (l <= r) {
		ll m = (l + r) / 2;
		if (foo(m)) {
			r = m - 1;
			if (ret > m)ret = m;
		}
		else l = m + 1;
	}
	if (p)
		cout << ret << '\n';
	else cout << -1 << '\n';
}