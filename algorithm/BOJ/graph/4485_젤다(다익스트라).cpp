#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int v, int c) {
		to = v;
		cost = c;
	}
};

bool check[127*127];
int d[127*127];
int inf = 987654321;
int pro = 1;
int a[127][127];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		vector<Edge>p[127*127];
		int n;
		cin >> n;
		if (n == 0)break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 1 && ny >=1 && nx <= n && ny <= n) {
						p[(i-1)*n + j].push_back(Edge((nx-1)*n + ny,a[nx][ny] ));
					}
				}
			}
		}
		for (int i = 1; i <= n*n; i++) {
			d[i] = inf;
		}
		d[1] = 0;
		memset(check, false, sizeof(check));
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, 1 });
		while (!pq.empty()) {
			auto pa = pq.top();
			pq.pop();
			int from = pa.second;
			if (check[from])continue;
			check[from] = true;
			for (int i = 0; i < p[from].size(); i++) {
				int to = p[from][i].to;
				int cost = p[from][i].cost;
				if (d[to] > d[from] + cost) {
					d[to] = d[from] + cost;
					pq.push({ -d[to],to });
				}
			}
		}
		cout << "Problem " << pro++ << ": " << d[n*n]+a[1][1] << '\n';
	}
}