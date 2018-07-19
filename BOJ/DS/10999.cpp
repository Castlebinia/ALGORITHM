#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
const int MAX = 1000001;
ll tree[MAX * 4];
ll ar[MAX];
ll lazy[MAX * 4];

ll init(int node, int start, int end) {
	if (start == end) return tree[node] = ar[start];
	int m = (start + end) / 2;
	return tree[node] = init(node * 2, start, m) + init(node * 2 + 1, m + 1, end);
}

void update_lazy(int node, int start, int end) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1)*lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(int node, int start, int end, int i, int j, ll diff) {
	update_lazy(node, start, end);
	if (i > end || j < start)return;
	if (i <= start && end <= j) {
		tree[node] += (end - start + 1)*diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int m = (start + end) / 2;
	update(node * 2, start, m, i, j, diff);
	update(node * 2 + 1, m + 1, end, i, j, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int start, int end, int i, int j) {
	update_lazy(node, start, end);
	if (i > end || j < start)return 0;
	if (i <= start && end <= j) return tree[node];
	int m = (start + end) / 2;
	return query(node * 2, start, m, i, j) + query(node * 2 + 1, m + 1, end, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> ar[i];
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c, d;
			cin >> b >> c >> d;
			update(1, 1, n, b, c, d);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << query(1, 1, n, b, c) << '\n';
		}
	}

}