#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<pair<int, int>>p;
bool check[103];
bool flag;
int n;

bool foo(int x1, int x2, int y1, int y2) {
	return (abs(x1 - x2) + abs(y1 - y2) <= 1000) ? true : false;
}

void dfs(int now) {
	check[now] = true;
	if (p[now].first == p[n + 1].first&&p[now].second == p[n + 1].second) {
		flag = true;
		return;
	}
	for (int i = 1; i < n + 2; i++) {
		if (!check[i] && foo(p[now].first, p[i].first, p[now].second, p[i].second)) {
			check[i] = true;
			dfs(i);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		flag = false;
		memset(check, false, sizeof(check));
		cin >> n;
		p.clear();
		for (int i = 0; i < n + 2; i++) {
			int x, y;
			cin >> x >> y;
			p.push_back({ x,y });
		}
		dfs(0);
		if (flag)cout << "happy\n";
		else cout << "sad\n";
	}
}