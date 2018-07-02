#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int ind[1002];

class Strahler {
public:
	int order=0;
	bool same=false;
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int ans = 0;
		memset(ind, 0, sizeof(ind));
		Strahler st[1002];
		vector<int> ve[1002];
		int k, m, p;
		cin >> k >> m >> p;
		while (p--) {
			int u, v;
			cin >> u >> v;
			ve[u].push_back(v);
			ind[v]++;
		}
		queue<int> q;
		for (int i = 1; i <= m; i++) {
			if (ind[i] == 0) {
				q.push(i);
				st[i].order = 1;
			}
		}
		while(!q.empty()){
			int x = q.front();
			q.pop();
			if (st[x].same)st[x].order++;
			ans = max(st[x].order, ans);
			for (int i = 0; i < ve[x].size(); i++) {
				int y = ve[x][i];
				if (st[x].order > st[y].order) {
					st[y].order = st[x].order;
					st[y].same = false;
				}
				else if (st[x].order == st[y].order) {
					st[y].same = true;
				}
				if (--ind[y] == 0)q.push(y);
			}
		}
		cout << k << ' ' << ans << '\n';
	}
}