#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll tree[1000001 * 4];
int ssize = 1;

void update(int i, ll x) {
	i += ssize;
	tree[i] = x;
	while (i > 1) {
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
	while (ssize <= n)ssize <<= 1;
	ssize--;
	while (m--) {
		ll op, a, b;
		cin >> op >> a >> b;
		if (!op) {
			if (a > b)swap(a, b);
			cout << query(1, 1, ssize, a, b) << '\n';
		}
		else update(a, b);
	}
}