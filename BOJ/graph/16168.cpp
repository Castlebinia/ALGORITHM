#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
vector<vector<int>>p;
bool visited[3001][3001];

void dfs(int now,int cnt) {
	if (cnt == m) {
		cout << "YES\n";
		exit(0);
	}
	for (auto next : p[now]) {
		if (visited[now][next]||visited[next][now])continue;
		visited[now][next] = visited[next][now] = true;
		dfs(next, cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	p.resize(n + 1);
	for(int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	for (int i = 1; i <= 1; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, 0);
		cout << '\n';
	}
	cout << "NO\n";
}