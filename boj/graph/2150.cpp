#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>>p, rp,ans;
bool visited[100001];
stack<int>st;
int idx;
int track[100001];

void dfs(int now,bool flag) {
	vector<vector<int>>&tmp = flag ? p : rp;
	visited[now] = true;
	for (auto next : tmp[now]) {
		if (!visited[next]) {
			visited[next] = true;
			dfs(next,flag);
		}
	}
	if(flag)st.push(now);
	else {
		ans[idx].push_back(now);
		track[now] = idx;
	}
}

void scc() {
	memset(visited, false, sizeof(visited));
	while (!st.empty()) {
		int now = st.top();
		st.pop();
		if (!visited[now]) {
			visited[now] = true;
			dfs(now,0);
			sort(ans[idx].begin(), ans[idx].end());
			idx++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	p.resize(n + 1), rp.resize(n + 1), ans.resize(n + 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		rp[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i]) {
			visited[i] = true;
			dfs(i,1);
		}
	}
	scc();
	memset(visited, false, sizeof(visited));
	cout << idx << '\n';
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			for (auto x : ans[track[i]]) {
				visited[x] = true;
				cout << x << ' ';
			}
			cout << "-1\n";
		}
	}
}