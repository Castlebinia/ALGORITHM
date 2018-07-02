#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool check[100001];
bool check2[100001];
int d[100001];
vector<vector<int>>p;

bool cmp(int x, int y) {
	return x > y;
}
int cret;
int dfs(int x) {
	check[x] = true;
	for (int i = 0; i < p[x].size();i++) {
		int next = p[x][i];
		if (!check[next] && !check2[next]) {
			check[next] = true;
			cret++;
			dfs(next);
		}
	}
	return cret;
}

void dfs2(int x) {
	check2[x] = true;
	for (int i = 0; i < p[x].size(); i++) {
		int next = p[x][i];
		if (!check2[next]) {
			check2[next] = true;
			dfs2(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	p.resize(n+1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		p[u].push_back(v);
		p[v].push_back(u);
	}
	int ret = 1;
	int c, h, k;
	cin >> c >> h >> k;

	dfs2(h);
	ret+=dfs(c);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i == c || i == h)continue;
		if (!check2[i]) {
			cret = 0;
			d[i]=dfs(i)+1;
			cnt++;
		}
	}
	sort(d, d + n,cmp);
	for (int i = 0; i < k; i++) {
		ret += d[i];
	}
	cout << ret << '\n';
}