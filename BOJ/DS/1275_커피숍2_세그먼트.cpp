#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int ssize = 1;
ll a[100001];
ll tree[100001 * 4];

void update(int i, ll x) {
	i += ssize;
	tree[i] = x;
	while (i >1) {
		i /= 2;
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

ll query(int node, int start, int end, int i, int j) {
	if (i > end || j < start)return 0;
	if (i <= start && end <= j)return tree[node];
	int m = (start + end) / 2;
	return query(node * 2, start, m, i, j) + query(node * 2 + 1, m + 1, end, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (n >= ssize)ssize <<= 1;
	ssize--;
	for (int i= 1; i <= n; i++) {
		cin >> a[i];
		update(i, a[i]);
	}
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y)swap(x, y);
		cout << query(1, 1, ssize, x, y) <<'\n';
		update(a, b);
	}
}