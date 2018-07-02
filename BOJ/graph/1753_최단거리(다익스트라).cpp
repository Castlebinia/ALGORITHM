#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to, cost;
	Edge(int v, int c) {
		to = v;
		cost = c;
	}
};

int d[20001];
bool check[20001];
int inf = 987654321;
vector<Edge>p[20001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int s;
	cin >> s;
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		p[u].push_back({ v,c });
	}
	for (int i = 1; i <= n; i++)d[i] = inf;
	d[s] = 0;
	priority_queue <pair<int,int>> pq;
	pq.push({ 0,s });
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
	for (int i = 1; i <= n; i++) {
		if (d[i] >= inf)cout << "INF\n";
		else cout << d[i] << '\n';
	}
}