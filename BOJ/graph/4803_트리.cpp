#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool check[501];
int v, e;
void dfs(int now, vector<vector<int>>&p) {
	v++;
	e += p[now].size();
	check[now] = true;
	for (auto next : p[now]) {
		if (!check[next]) {
			check[next] = true;
			dfs(next, p);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 0;
	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)return 0;
		memset(check, 0, sizeof(check));
		vector<vector<int>>p;
		p.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			p[u].push_back(v);
			p[v].push_back(u);
		}
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {	//component
				v = e = 0;
				dfs(i, p);
				if ((v - 1) * 2 == e)ret++;
			}
		}
		t++;
		if (ret >= 2) cout << "Case " << t << ": A forest of " << ret << " trees.\n";
		else if (ret == 1) cout << "Case " << t << ": There is one tree.\n";
		else cout << "Case " << t << ": No trees.\n";
	}
}