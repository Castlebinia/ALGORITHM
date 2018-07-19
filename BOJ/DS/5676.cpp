#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int ssize = 1;

int tree[100000 * 4];

void update(int i, int x) {
	i += ssize;
	tree[i] = x;
	while (i != 1) {
		i /= 2;
		tree[i] = tree[i * 2] * tree[i * 2 + 1];
	}
}

int query(int node, int start, int end, int i, int j) {
	if (i > end || start > j)return 1;
	if (i <= start && end <= j)return tree[node];
	int m = (start + end) / 2;
	return query(node * 2, start, m, i, j)*query(node * 2 + 1, m + 1, end, i, j);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	while (cin>>n){
		cin >> k;
		ssize = 1;
		while (ssize <= n)ssize <<= 1;
		ssize--;
		for (int i = 1; i <= ssize; i++)tree[i] = 1;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			if (x > 0)x = 1;
			else if (x < 0)x = -1;
			update(i, x);
		}
		string ans = "";
		for (int i = 0; i < k; i++) {
			string op;
			cin >> op;
			if (op == "C") {
				int i, x;
				cin >> i >> x;
				if (x > 0)x = 1;
				else if (x < 0)x = -1;
				update(i, x);
			}
			else {
				int a, b;
				cin >> a >> b;
				int tmp = query(1, 1, ssize, a, b);
				if (tmp > 0)ans += "+";
				else if (tmp < 0)ans += "-";
				else ans += "0";
			}
		}
		cout << ans << '\n';
	}
}
