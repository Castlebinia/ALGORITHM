#include <iostream>
#include <cstring>

using namespace std;

int ssize = 1;
int tree[100001 * 2 * 4];
int saw[100001 * 2 * 4];
bool see[100001];

void update(int i, int x) {
	i += ssize;
	tree[i] = x;
	while (i != 1) {
		i /= 2;
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

int query(int node, int start, int end, int i, int j) {
	if (i > end || start > j)return 0;
	if (i <= start && end <= j)return tree[node];
	int m = (start + end) / 2;
	return query(node * 2, start, m, i, j) + query(node * 2 + 1, m + 1, end, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		memset(tree, 0, sizeof(tree));
		memset(saw, 0, sizeof(saw));
		ssize = 1;
		while (ssize <= (n + m))ssize <<= 1;
		ssize--;
		for (int i = 1; i <= n; i++) {
			update(m + i, 1);
			saw[i] = i + m;
		}
		int idx = m;
		for (int i = 1; i <= m; i++) {
			int tmp;
			cin >> tmp;
			cout << query(1, 1, ssize, 1, saw[tmp] - 1) << ' ';
			update(saw[tmp], 0);
			saw[tmp] = --idx;
			update(saw[tmp], 1);
		}
		cout << '\n';
	}
}