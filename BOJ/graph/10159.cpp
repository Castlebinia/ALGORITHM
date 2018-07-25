#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool check[101][101];
vector<vector<int>>p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	p.resize(n + 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (auto next : p[now]) {
				if (!check[i][next]) {
					check[i][next] = true;
					q.push(next);
				}
			}
		}
		check[i][i] = true;
	}
	int ret;
	for (int i = 1; i <= n; i++) {
		ret = 0;
		for (int j = 1; j<=n; j++) {
			if (!check[i][j]&&!check[j][i])ret++;
		}
		cout << ret << '\n';
	}
}