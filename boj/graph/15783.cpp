#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;
vector<vector<int>>p;
bool visited[100001];
stack<int>st;

void dfs(int now) {
	visited[now] = true;
	for (auto next : p[now]) {
		if (!visited[next]) {
			visited[next] = true;
			dfs(next);
		}
	}
	st.push(now);
}

int scc() {
	int ret = 0;
	while (!st.empty()) {
		int now = st.top();
		st.pop();
		if (!visited[now]) {
			dfs(now);
			ret++;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	p.resize(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		p[a].push_back(b);
	}
	for (int i = 0; i < n; i++) if (!visited[i])dfs(i);
	memset(visited, false, sizeof(visited));
	cout << scc() << '\n';
}