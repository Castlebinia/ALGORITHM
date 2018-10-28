#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	vector<vector<int>>p;
	int n, m;
	cin >> n >> m;
	p.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		p[a].push_back(b);
	}
	int ret = 0;
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
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (check[i][j] || check[j][i])cnt++;
		}
		if (cnt == n - 1)ret++;
	}
	cout << ret << '\n';
}