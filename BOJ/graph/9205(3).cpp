#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

bool check[103];

bool foo(int x1, int x2, int y1, int y2) {
	if (abs(x1 - x2) + abs(y1 - y2) <= 1000)return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>>p;
		memset(check, false, sizeof(check));
		for (int i = 0; i < n + 2; i++) {
			int x, y;
			cin >> x >> y;
			p.push_back({ x,y });
		}
		bool flag = false;
		queue<int>q;
		q.push(0);
		check[0] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (p[now].first == p[n + 1].first&&p[now].second == p[n + 1].second) {
				flag = true;
				break;
			}
			for (int i = 1; i < n + 2; i++) {
				if (!check[i] && foo(p[now].first, p[i].first, p[now].second, p[i].second)) {
					check[i] = true;
					q.push(i);
				}
			}
		}
		if (flag)cout << "happy\n";
		else cout << "sad\n";
	}
}