#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int p[102];
vector<int>ans;
bool check[101];
bool fin[101];
int n;

void dfs(int now,int start) {
	check[now] = true;
	if (now == start) {
		for (int i = 1; i <= n; i++) {
			if (check[i]) {
				ans.push_back(i);
				fin[i] = true;
			}
		}
		return;
	}
	int next = p[now];
	if (!check[next] && !fin[next])dfs(next, start);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		if (!fin[i]) {
			memset(check, false, sizeof(check));
			dfs(p[i], i);
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto x : ans)cout << x << '\n';
}