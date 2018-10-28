#include <iostream>

using namespace std;
int d[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][k] && d[k][j])d[i][j] = 1;
			}
		}
	}
	int ret = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (d[i][j]||d[j][i])cnt++;
		}
		if (cnt == n - 1)ret++;
	}
	cout << ret << '\n';
}