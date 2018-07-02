#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int>p[200001];
bool check[200001];
int d[200001];

int dfs(int x) {
	int ret = 0;
	if (p[x].size() == 2)ret = 1;
	for (int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if (!check[y]) {
			check[y] = true;
			dfs(y);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		d[i] = dfs(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (d[i] == 1 && d[i + 1] == 1)ans++;
		}
		else if (d[i] == 1&&d[i-1]==0 &&d[i+1]==1) {
			ans++;
		}
	}
	cout << ans << '\n';
}