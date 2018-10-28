#include <iostream>
#include <algorithm>
using namespace std;

int d[401][401];
int inf = 987654321;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
		  d[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		if (d[u-1][v-1] > c)d[u-1][v-1] = c;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ret = inf;
	for (int i = 0; i < n; i++) {
		if (d[i][i] < ret)ret = d[i][i];
	}
	if (ret == inf)cout << -1 << '\n';
	else cout << ret << '\n';

}