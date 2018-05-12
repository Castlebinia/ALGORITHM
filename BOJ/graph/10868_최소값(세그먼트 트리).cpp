#include <iostream>
#include <algorithm>

using namespace std;
int inf = 0x3f3f3f3f;

int a[100001];
int tree[4*100001];

int init(int node, int start, int end) {
	if (start == end) return tree[node] = a[start];
	return tree[node] = min(init(2 * node, start, (start + end) / 2), 
		init(2 * node + 1, (start + end) / 2 + 1, end));
}

int query(int node, int start, int end, int i, int j) {
	if (i > end || j < start)return inf;
	if (i <= start && end <= j)return tree[node];
	int mid = (start + end) / 2;
	return min(query(node*2, start, mid, i, j), query(node*2+1, mid + 1, end, i, j));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> a[i];
	init(1, 0, n - 1);
	while (m--) {
		int left, right;
		cin >> left >> right;
		cout << query(1, 0,n-1,left-1,right-1) << '\n';
	}
}