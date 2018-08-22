#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k, d[1 << 16], cost[16][16];
const int INF = 0x3f3f3f3f;

bool cnt(int visited) {
	int ret = 0;
	int tmp = visited;
	while (tmp) {
		ret += (tmp & 1);
		tmp >>= 1;
	}
	return ret >= k;
}

int solve(int visited) {
	if (cnt(visited)) return 0;
	int &ret = d[visited];
	if (ret != -1)return ret;
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visited&(1 << i)) {
		for (int j = 0; j < n; j++) {
				if (i==j||visited&(1<<j))continue;
				ret = min(ret, solve(visited | (1 << j)) + cost[i][j]);
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)cin >> cost[i][j];
	int visited = 0;
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		if (tmp == 'Y')visited |= 1 << i;
	}
	cin >> k;
	memset(d, -1, sizeof(d));
	int ret = solve(visited);
	cout << (ret != INF ? ret : -1) << '\n';
}