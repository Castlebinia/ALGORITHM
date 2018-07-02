#include <iostream>
#include <vector>

using namespace std;
int d[501];
int inf = 987654321;
struct Edge {
	int from, to, cost;
	Edge(int u, int v, int c) {
		from = u;
		to = v;
		cost = c;
	}
};

vector<Edge>p;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	bool negative = false;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		p.push_back(Edge(v, u, c));
	}
	for (int i = 1; i <= n; i++)d[i] = inf;
	d[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int to = p[j].to;
			int from = p[j].from;
			int cost = p[j].cost;
			if (d[to] != inf && d[to] + cost < d[from]) {
				d[from] = d[to] + cost;
				if (i == n)negative = true;
			}
		}
	}
	if (negative)cout << -1 << '\n';
	else {
		for (int i = 2; i <= n; i++) {
			if (d[i] == inf)cout << -1 << '\n';
			else cout << d[i] << '\n';
		}
	}
}