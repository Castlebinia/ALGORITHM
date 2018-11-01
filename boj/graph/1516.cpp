#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>>p;
int ind[501], ret[501], cost[501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	p.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		while (true) {
			int x;
			cin >> x;
			if (x == -1)break;
			ind[i]++;
			p[x].push_back(i);
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (!ind[i])
		{
			ret[i] = cost[i];
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = q.front();
		q.pop();
		for (auto next : p[x]) {
			ret[next] = max(ret[next], cost[next] + ret[x]);
			if (--ind[next] == 0) q.push(next);
		}
	}
	for (int i = 1; i <= n; i++)cout << ret[i] << '\n';
}
