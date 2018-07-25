#include <iostream>

using namespace std;
int p[402][402];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, s;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		p[u][v] = -1;
		p[v][u] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[i][k] == 1 && p[k][j] == 1) {
					p[i][j] = 1;
					p[j][i] = -1;
				}
			}
		}
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		int u, v;
		cin >> u >> v;
		cout << p[u][v] << '\n';
	}
}