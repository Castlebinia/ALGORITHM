#include <iostream>
#include <vector>

using namespace std;

int ssize = 1;
int ret[100002];
int tree[100002 * 4];

void update(int i, int x) {
	i += ssize;
	tree[i] = x;
	while (i != 1) {
		i /= 2;
		tree[i] = (tree[2 * i] + tree[2 * i + 1]);
	}
}

int query(int node, int x,int i,int j) {
	int m = (i + j) / 2;
	if (i == j)return i;
	if (tree[node * 2] > x)return query(node * 2, x,i, m);
	else return query(node * 2 + 1,x-tree[node*2], m + 1, j);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (ssize <= n)ssize <<= 1;
	ssize--;
	for (int i = 1; i <=n; i++) {
		update(i, 1);
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int tmp = query(1, x, 1, ssize);
		ret[tmp] = i;
		update(tmp, 0);
	}
	for (int i = 1; i <= n; i++)cout << ret[i] << '\n';
}