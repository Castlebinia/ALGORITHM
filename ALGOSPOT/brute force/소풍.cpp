#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

bool check[11];
bool friends[11][11];

int foo(int n) {
	int ret = 0;
	int start = -1;
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			start = i;
			break;
		}
	}
	if (start==-1)return 1;
	for (int i = start+1; i < n; i++) {
		if (!check[i]&&friends[start][i]) {
			check[i] = true;
			check[start] = true;
			ret += foo(n);
			check[i] = false;
			check[start] = false;
		}
	}
	return ret;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(check, false, sizeof(check));
		memset(friends, false, sizeof(friends));
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			friends[u][v] = true;
			friends[v][u] = true;
		}
		cout << foo(n) << '\n';
	}
}