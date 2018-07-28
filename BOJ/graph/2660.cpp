#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;

int d[51][51];
int score[51];

void init(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)d[i][j] = (i == j) ? 0 : INF;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	init(n);
	while (true) {
		int u, v;
		cin >> u >> v;
		if (u == -1 && v == -1)break;
		d[u][v] = d[v][u] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ret = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			if (d[i][j] != INF)score[i] = max(score[i], d[i][j]);
		ret = min(score[i], ret);
	}
	vector<int>p;
	for (int i = 1; i <= n; i++)if (score[i] == ret)p.push_back(i);
	cout << ret << ' ' << p.size() << '\n';
	for (auto x : p)cout << x << ' ';
	cout << '\n';
}