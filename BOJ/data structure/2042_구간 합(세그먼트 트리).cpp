#include <iostream>

using namespace std;

typedef long long ll;

ll tree[4*1000001];
ll ar[1000001];

ll init(int node, int start, int end) {
	if (start == end)return tree[node] = ar[start];
	return tree[node] = init(node * 2, start, (start + end) / 2) + 
		init(node * 2 + 1, (start + end) / 2 + 1, end);
}

void update(int node, int start, int end, int find,ll diff) {
	if (find<start || find>end)return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(2 * node, start, (start + end) / 2, find, diff);
		update(2 * node + 1, (start + end) / 2+1, end, find, diff);
	}
}

ll query(int node, int start, int end, int i, int j) {
	if (i >end || j < start)return 0;
	if (i <= start && end <= j)return tree[node];
	return query(2 * node, start, (start + end) / 2, i, j) + 
		query(2 * node + 1, (start + end) / 2 + 1, end, i, j);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			ll diff = c - ar[b - 1];
			ar[b - 1] = c;
			update(1, 0, n - 1, b - 1, diff);
		}
		else {
			cout << query(1, 0, n - 1, b - 1, c-1) << '\n';
		}
	}
}
