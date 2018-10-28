#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ssize = 1;
int tree[40001 * 4];

void update(int i, int x) {
	i += ssize;
	tree[i] = x;
	while (i != 1) {
		i /= 2;
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	}
}

int query(int node, int start, int end, int i, int j) {
	if (i > end || start > j)return 0;
	if (i <= start && end <= j)return tree[node];
	int m = (start + end) / 2;
	return max(query(node * 2, start, m, i, j), query(node * 2 + 1, m + 1, end, i, j));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (ssize <= n)ssize <<= 1;
	ssize--;
	vector<pair<int, int>>p;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		p.push_back({ x,i });
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < n; i++) {
		int pi = p[i].second;
		int tmp = query(1, 1, ssize, 1, pi);
		update(pi, tmp + 1);
	}
	cout << tree[1] << '\n';
}