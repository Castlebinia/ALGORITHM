#include <iostream>

using namespace std;

using ll = long long;

ll tree[1000001*4];
int num = 1;

void update(int i, ll x) {
	i += num;
	tree[i] += x;
	while (i != 1) {
		i /= 2;
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

ll query(int node, int start, int end, int i, int j) {
	if (i > end || j < start)return 0;
	if (i <= start && end<= j) return tree[node];
	return query(node * 2, start, (start + end) / 2, i, j) +
		query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin >> n >> m;
	while (num < n)num <<= 1;
	num--;
	for (int i = 0; i < m; i++) {
		ll op, a, b;
		cin >> op >> a >> b;
		if (op == 1) {
			update(a, b);
		}
		else {
			cout << query(1, 1, num, a,b) << '\n';
		}
	}
}