#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool check[100001];
bool fin[100001];
int p[100001];
int cnt;

void dfs(int now) {
	check[now] = true;
	int next = p[now];
	if (!check[next]) {
		dfs(next);
	}
	else {
		if (!fin[next]) {
			for (int tmp = next; tmp != now; tmp = p[tmp])cnt++;
			cnt++;
		}
	}
	fin[now] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cnt = 0;
		memset(check, false, sizeof(check));
		memset(fin, false, sizeof(check));
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i])dfs(i);
		}
		cout << n - cnt << '\n';
	}
}