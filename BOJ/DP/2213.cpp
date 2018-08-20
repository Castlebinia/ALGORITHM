#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int cost[10001], d[10001][2];
vector<vector<int>>tree, p;
vector<int>ans;
bool visited[10001];

void dfs(int now) {
	visited[now] = true;
	for (auto next : p[now]) {
		if (!visited[next]) {
			tree[now].push_back(next);
			dfs(next);
		}
	}
}

int foo(int now,int k) {
	int &ret = d[now][k];
	if (ret != -1)return ret;
	ret = (k == 1) ? cost[now] : 0;
	for (auto next : tree[now]) {
		if (!k) ret += max(foo(next, 0), foo(next, 1));
		else ret += foo(next, 0);
	}
	return ret;
}

void trace(int now, int k) {
	if (!k) {
		for (auto next : tree[now]) {
			if (d[next][0] < d[next][1])trace(next, 1);
			else trace(next, 0);
		}
	}
	else {
		ans.push_back(now);
		for (auto next : tree[now])trace(next, 0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	tree.resize(n + 1), p.resize(n + 1);
	for (int i = 1; i <= n; i++)cin >> cost[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	dfs(1);
	memset(d, -1, sizeof(d));
	foo(1, 0); foo(1, 1);
	if (d[1][1] >= d[1][0]) {
		cout << d[1][1] << '\n';
		trace(1, 1);
	}
	else {
		cout << d[1][0]<< '\n';
		trace(1, 0);
	}
	sort(ans.begin(), ans.end());
	for (auto x : ans) cout << x << ' ';
	cout << '\n';
}