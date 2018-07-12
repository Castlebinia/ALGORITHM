#include <iostream>

using namespace std;

using ll = long long;
int n, m;

ll a[10001];
ll tree[10001 * 4];

void update(int node, int start, int end, int find, ll diff) {
	if (find<start || find>end)return;
	tree[node] += diff;
	if (start != end) {
		update(2 * node, start, (start + end) / 2, find, diff);
		update(2 * node + 1, (start + end) / 2 + 1, end, find, diff);
	}
}

ll query(int node, int start, int end, int i, int j) {
	if (i > end || j < start)return 0;
	if (i <= start && end <= j) return tree[node];
	return query(node * 2, start, (start + end) / 2, i, j) +
		query(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int op, p, x;
		cin >> op >> p >> x;
		if (op == 1) {
			update(1,1,n,p,x);
		}
		else {
			cout << query(1, 1, n, p, x) << '\n';
		}
	}
}