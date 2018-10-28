#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int inf = 987654231;
int d[102][102];
int v[102][102];
int prev[102][102];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)d[i][j] = 0;
			else d[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		d[u - 1][v - 1] = min(d[u - 1][v - 1], c);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i][j] = j;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
					v[i][j] = v[i][k];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || d[i][j] == inf) {
				cout << "0\n";
				continue;
			}
			else {
				vector<int> path;
				for (int k = i;k!=j; k = v[k][j]) {
					path.push_back(k+1);
				}
				path.push_back(j + 1);
				cout << path.size() << ' ';
				for (int i = 0; i < path.size(); i++) {
					cout << path[i] << ' ';
				}
				cout << '\n';
			}
		}
	}
}