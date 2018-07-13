#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ssize = 1;
int tree[100001 * 4];

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
	return query(node * 2, start, m, i, j)+ query(node * 2 + 1, m + 1, end, i, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (ssize <= n)ssize <<= 1;
	ssize--;
	vector<pair<int,int>>p;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		p.push_back({ x,i });
		update(i, 1);
	}
	sort(p.begin(), p.end());
	int left = 0, right = n-1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0) {
			cout << query(1, 1, ssize, 1, p[left].second-1) << '\n';
			update(p[left].second, 0);
			left++;
		}
		else {
			cout << query(1, 1, ssize, p[right].second+1, n) << '\n';
			update(p[right].second, 0);
			right--;
		}
	}
}