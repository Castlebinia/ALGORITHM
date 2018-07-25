#include <iostream>

using namespace std;

int d[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		d[u][v] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] && d[k][j]) {
					d[i][j] = 1;
				}
			}
		}
	}
	int ret;
	for (int i = 1; i <= n; i++) {
		ret = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)continue;
			if (!d[i][j] && !d[j][i])ret++;
		}
		cout << ret << '\n';
	}

}