#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int d[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = INF;
		}
		d[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		d[u][v] = min(d[u][v], c);
	}
	for(int k=0;k<n;k++){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (d[i][j]==INF?0:d[i][j]) << ' ';
		}
		cout << '\n';
	}
}