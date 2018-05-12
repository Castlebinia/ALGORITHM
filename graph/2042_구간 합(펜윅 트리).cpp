#include <iostream>

using namespace std;

typedef long long ll;
int n, m, k;

ll tree[1000001];
ll ar[1000001];

void update(int i, ll diff) {
	while (i < n+1) {
		tree[i] += diff;
		i += (i & -i);
	}
}

ll sum(int i) {
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
		update(i, ar[i]);
	}
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - ar[b];
			ar[b] = c;
			update(b,diff);
		}
		else {
			cout << sum(c)-sum(b-1) << '\n';
		}
	}
}
