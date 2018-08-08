#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
stack<int>st;
vector<vector<int>>p, rp, scc;
const int MAX = 100001;
bool check[MAX];
int track[MAX], ind[MAX];
int idx;

void dfs(int now,bool flag) {
	check[now] = true;
	vector<vector<int>>&tmp = flag ? p : rp;
	for (auto next : tmp[now]) {
		if (!check[next]) {
			dfs(next,flag);
		}
	}
	if(flag)st.push(now);
	else {
		scc[idx].push_back(now);
		track[now] = idx;
	}
}

void foo() {
	memset(check, false, sizeof(check));
	while (!st.empty()) {
		int now = st.top();
		st.pop();
		if (!check[now]) {
			dfs(now, false);
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
		p.clear(), rp.clear(), scc.clear();
		idx = 0;
		memset(check, false, sizeof(check));
		memset(ind, 0, sizeof(ind));
		int n, m;
		cin >> n >> m;
		p.resize(n); rp.resize(n), scc.resize(n);
		while (m--) {
			int u, v;
			cin >> u >> v;
			p[u].push_back(v);
			rp[v].push_back(u);
		}
		for (int i = 0; i < n; i++) {
			if (!check[i])dfs(i, true);
		}
		foo();
		for (int i = 0; i < n; i++) {
			for (auto next : p[i]) {
				if (track[i] != track[next])ind[track[next]]++;
			}
		}
		int cnt, ret;
		cnt = ret = 0;
		for (int i = 0; i < idx; i++) {
			if (!ind[i]) { cnt++, ret = i; }
		}
		if (cnt > 1)cout << "Confused\n";
		else {
			sort(scc[ret].begin(), scc[ret].end());
			for (auto x : scc[ret])cout << x << '\n';
		}
		cout << '\n';
	}
}