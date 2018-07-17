#include <iostream>
#include <vector>

using namespace std;
int d[500001];
bool check[500001];
vector<vector<int>>p;

void dfs(int now) {
	check[now] = true;
	for (auto next : p[now]) {
		if (!check[next]) {
			check[next] = true;
			d[next] += d[now]+1;
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	p.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	dfs(1);
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i].size() == 1)ret += d[i];
	}
	if (ret % 2 == 0)cout << "No\n";
	else cout << "Yes\n";
}