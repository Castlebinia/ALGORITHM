#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>p[1001];
bool check[1001];
int ans[1001];

int main() {
	int a, b;
	cin >> a >> b;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	int ret = 0;
	queue<int> q;
	bool flag = false;
	q.push(a);
	check[a] = true;
	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			int here = q.front();
			q.pop();
			if (here == b) {
				flag = true;
				cout << ret << '\n';
				break;
			}
			for (int i = 0; i < p[here].size(); i++) {
				int there = p[here][i];
				if (!check[there]) {
					check[there] = true;
					q.push(there);
				}
			}
		}
		ret++;
	}
	if (!flag)cout << -1 << '\n';
}