#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

class Edge {
public:
	int u, v, cost;
	Edge() {}
	Edge(int u, int v, int c) :u(u), v(v), cost(c) { }
	bool operator <(const Edge&other)const {
		return cost < other.cost;
	}
};

int uf[200001];

int Find(int x) {
	if (x == uf[x])return x;
	else return uf[x] = Find(uf[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	uf[x] = y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		memset(uf, false, sizeof(uf));
		int ret = 0;
		int m, n;
		cin >> n >> m;
		if (m == 0 && n == 0)break;
		for (int i = 0; i < n; i++)uf[i] = i;
		vector<Edge>p(m);
		for(int i=0;i<m;i++){
			int u, v, c;
			cin >> u >> v >> c;
			p[i] = Edge(u, v, c);
			ret += c;
		}
		sort(p.begin(), p.end());
		for (int i = 0; i < m; i++) {
			Edge e = p[i];
			int u = Find(p[i].u);
			int v = Find(p[i].v);
			if (u != v) {
				Union(e.u, e.v);
				ret -= e.cost;
			}
		}
		cout << ret << '\n';
	}
}