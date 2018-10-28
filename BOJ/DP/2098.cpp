#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cost[16][16], d[16][1 << 16], n;
const int INF = 0x3f3f3f3f;

int foo(int now, int visited) {
	int &ret = d[now][visited];
	if (ret != -1)return ret;
	if (visited == (1 << n) - 1) {
		if (cost[now][0] != 0)return cost[now][0];
		else return INF;
	}
	ret = INF;
	for (int i = 0; i < n; i++) {
		if (visited&(1 << i) || !cost[now][i])continue;
		ret = min(ret, foo(i, visited | (1 << i))+cost[now][i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)cin >> cost[i][j];
	}
	memset(d, -1, sizeof(d));
	int ret = foo(0, 1);
	if (ret == INF)cout << -1 << '\n';
	else cout << ret << '\n';
}