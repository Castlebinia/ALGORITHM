#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check[501];
vector<vector<int>>p;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	p.resize(n + 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	int ret = p[1].size();
	check[1] = true;
	for (auto now : p[1]) check[now] = true;
	for (auto now : p[1]){
		for (auto next : p[now]) {
			if (!check[next]) {
				check[next] = true;
				ret++;
			}
		}
	}
	cout << ret << '\n';
}