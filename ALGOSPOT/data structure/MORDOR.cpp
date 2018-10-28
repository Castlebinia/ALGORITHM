#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int ssize = 1;
int tree[100001 * 4];
int tree2[100001 * 4];
int a[100001];
const int INF = 0x3f3f3f3f;

void update(int i, int x,int tree[]) {
	i += ssize;
	tree[i] = x;
	while (i > 1) {
		i /= 2;
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	}
}

int query(int node, int start, int end, int i, int j,int tree[]) {
	if (i > end || j < start) return INF;
	if (i <= start && end <= j)return tree[node];
	int m = (start + end) / 2;
	return min(query(node * 2, start, m, i, j,tree), query(2 * node + 1, m + 1, end, i, j,tree));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		ssize = 1;
		while (ssize <= n)ssize <<= 1;
		ssize--;
		memset(tree, 0, sizeof(tree));
		memset(tree2, 0, sizeof(tree2));
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			update(i, x,tree);
			update(i, -x, tree2);
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a++, b++;
			int min = query(1, 1, ssize, a, b,tree);
			int max = query(1, 1, ssize, a, b, tree2);
			cout << -max - min << '\n';
		}
	}
}