#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct edge {
	int to, cost;
};
struct ret {
	int cost, size;
};
const int INF = 0x3f3f3f3f;
vector<vector<edge>>p;
ret d[101];
bool visited[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	p.resize(n + 1);
	while (m--) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		int cost = 0;
		if (e >= 10)cost = c + (e - 10)*d;
		else cost = c;
		p[a].push_back({ b,cost });
	}
	for (int i = 1; i <= n; i++)d[i].cost = d[i].size = INF;
	priority_queue<pair<int,int>>pq;
	pq.push({ 0,1 });
	d[1].cost = 0, d[1].size = 1;
	while (!pq.empty()) {
		auto now = pq.top().second;
		pq.pop();
		if (visited[now])continue;
		visited[now] = true;
		for (auto next : p[now]) {
			if (d[next.to].cost == d[now].cost + next.cost) {
				if (d[next.to].size > d[now].size+1) {
					d[next.to].size = d[now].size+1;
					pq.push({ -d[next.to].cost,next.to });
				}
			}
			else if (d[next.to].cost > d[now].cost + next.cost) {
				d[next.to].cost = d[now].cost + next.cost;
				d[next.to].size = d[now].size + 1;
				pq.push({ -d[next.to].cost,next.to });
			}
		}
	}
	if (d[n].cost == INF)cout << "It is not a great way.\n";
	else cout << d[n].cost << ' ' << d[n].size << '\n';
}