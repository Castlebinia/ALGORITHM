#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int a[10001], d[10001][2];
vector<vector<int>>p, tree;
bool visited[10001];

void make_tree(int now) {
	visited[now] = true;
	for (auto &next : p[now]) {
		if (!visited[next]) {
			tree[now].push_back(next);
			make_tree(next);
		}
	}
}

int solve(int now, int k) {
	int &ret = d[now][k];
	if (ret != -1)return ret;
	ret = k ? a[now] : 0;
	for (auto &next : tree[now]) {
		if (k == 1)ret += solve(next, 0);
		else ret += max(solve(next, 1), solve(next, 0));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(d, -1, sizeof(d));
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	p.resize(n + 1); tree.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	make_tree(1);
	cout << max(solve(1, 0), solve(1, 1)) << '\n';

}