#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>>p, rp;
bool visited[100001];
int ind[100001];
int idx;
int track[100001];
stack<int>st;

void dfs(int now, bool flag) {
	vector<vector<int>>&tmp = flag ? p : rp;
	visited[now] = true;
	for (auto next : tmp[now]) {
		if (!visited[next]) {
			visited[next] = true;
			dfs(next, flag);
		}
	}
	if (flag)st.push(now);
	else track[now] = idx;
}

void foo() {
	memset(visited, false, sizeof(visited));
	while (!st.empty()) {
		int now = st.top();
		st.pop();
		if (!visited[now]) {
			dfs(now, 0);
			idx++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		memset(visited, false, sizeof(visited));
		memset(ind, 0, sizeof(ind));
		p.clear(), rp.clear();
		idx = 0;
		int n, m;
		cin >> n >> m;
		p.resize(n + 1), rp.resize(n + 1);
		int ret = 0;
		while (m--) {
			int u, v;
			cin >> u >> v;
			p[u].push_back(v);
			rp[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i])dfs(i, 1);
		}
		foo();
		for (int i = 1; i <= n; i++) {
			for (int j : p[i]) {
				if (track[i] != track[j])ind[track[j]]++;
			}
		}
		for (int i = 0; i < idx; i++) if (!ind[i])ret++;
		cout << ret << '\n';
	}
}