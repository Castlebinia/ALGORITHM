#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int ssize = 1;
ll ar[1001];
ll tree[1001 * 4];

void update(ll x, int i) {
	i += ssize;
	tree[i] = x;
	while (i != 0) {
		i /= 2;
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

ll query(int node, int start, int end, int i, int j) {
	if (j<start || i>end)return 0;
	if (i <= start && end <= j)return tree[node];
	int m = (start + end) / 2;
	return query(node * 2, start, m, i, j) + query(node * 2 + 1, m + 1, end, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	while (ssize <= n)ssize <<= 1;
	ssize--;
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
		update(ar[i], i);
	}
	while (q--) {
		int x;
		cin >> x;
		if (x == 1) {
			int a, b;
			cin >> a >> b;
			cout << query(1, 1, ssize, a, b) << '\n';
			swap(ar[a], ar[b]);
			update(ar[a], a);
			update(ar[b], b);
		}
		else {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			cout << query(1, 1, ssize, a, b) - query(1, 1, ssize, c, d) << '\n';
		}
	}
}