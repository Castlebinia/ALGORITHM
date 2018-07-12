#include <iostream>
#include <algorithm>

using namespace std;

int a[100002];
int max_tree[100002 * 4];
int min_tree[100002 * 4];

int max_init(int node, int start, int end) {
	if (start == end) return max_tree[node] = a[start];
	int m = (start + end) / 2;
	return max_tree[node] = max(max_init(node * 2, start, m), max_init(node * 2 + 1, m + 1, end));
}
int min_init(int node, int start, int end) {
	if (start == end) return min_tree[node] = a[start];
	int m = (start + end) / 2;
	return min_tree[node] = min(min_init(node*2,start,m),min_init(node*2+1,m+1,end));
}

int max_query(int node, int start, int end, int i, int j) {
	if (i>end||j<start)return 0;
	if (i<=start&&end<=j) return max_tree[node];
	return max(max_query(node * 2, start, (start + end) / 2,i,j), 
		max_query(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}
int min_query(int node, int start, int end, int i, int j) {
	if (i>end||j<start)return 0x3f3f3f3f;
	if (i<=start&&end<=j)return min_tree[node];
	return min(min_query(node * 2, start, (start + end) / 2, i, j), 
		min_query(node * 2 + 1, (start + end) / 2+1, end, i, j));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	max_init(1, 1, n);
	min_init(1, 1, n);
	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << min_query(1, 1, n, i, j)<<' '<< max_query(1, 1, n, i, j) << '\n';
	}
}