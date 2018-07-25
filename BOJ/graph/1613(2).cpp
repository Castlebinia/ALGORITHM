#include <iostream>
#include <queue>

using namespace std;
bool check[401][401];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>>p;
	int n, k, s;
	cin >> n >> k;
	p.resize(n + 1);
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		while (!q.empty()) {
			int tmp = q.front();
			q.pop();
			for (auto next : p[tmp]) {
				if (!check[i][next]) {
					check[i][next] = true;
					q.push(next);
				}
			}
		}
	}
	cin >> s;
	while (s--) {
		int u, v;
		cin >> u >> v;
		if (check[u][v])cout << -1 << '\n';
		else if (check[v][u])cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}