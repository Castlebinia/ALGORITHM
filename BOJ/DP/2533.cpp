#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
vector<vector<int>>p, tree;
bool visited[1000001];
int d[1000001][2];

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
	if (!tree[now].size())return ret=k;
	if (ret != -1)return ret;
	ret = k;
	for (auto &next : tree[now]) {
		if (k==0)ret += solve(next, 1);
		else ret += min(solve(next, 0), solve(next, 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	memset(d, -1, sizeof(d));
	p.resize(n + 1), tree.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	make_tree(1);
	cout << min(solve(1, 0), solve(1, 1)) << '\n';
}