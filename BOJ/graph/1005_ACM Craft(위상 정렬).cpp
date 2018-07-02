#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int time[1001];
int ind[1001];
int ret[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(time, 0, sizeof(time));
		memset(ind, 0, sizeof(ind));
		memset(ret, 0, sizeof(ret));
		int n, m;
		cin >> n >> m;
		vector<int>p[1001];
		for (int i = 1; i <= n; i++)cin >> time[i];
		int u, v;
		while (m--) {
			cin >> u >> v;
			ind[v]++;
			p[u].push_back(v);
		}
		int ans;
		cin >> ans;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				q.push(i);
				ret[i] = time[i];
			}
		}
		for (int k = 1; k <= n; k++) {
			if (ind[ans] == 0) {
				cout << ret[ans] << '\n';
				break;
			}
			int x = q.front();
			q.pop();
			for (int i = 0; i < p[x].size(); i++) {
				int y = p[x][i];
				ret[y] = max(ret[y], ret[x] + time[y]);
				if (--ind[y] == 0)q.push(y);
			}
		}
	}
}