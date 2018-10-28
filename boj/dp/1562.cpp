#include <iostream>
#include <cstring>

using namespace std;
const int MOD = 1e+9;

int n, d[100][10][1 << 10];

int solve(int pos, int last, int visited) {
	if (pos == n) {
		return (visited == (1 << 10) - 1);
	}
	int &ret = d[pos][last][visited];
	if (ret != -1)return ret;
	ret = 0;
	if (last + 1 < 10) {
		ret += solve(pos + 1, last + 1, visited | 1 << (last + 1)) % MOD;
		ret %= MOD;
	}
	if (last - 1 >= 0) {
		ret += solve(pos + 1, last - 1, visited | 1 << (last - 1)) % MOD;
		ret %= MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(d, -1, sizeof(d));
	int ret = 0;
	for (int i = 1; i <= 9; i++) {
		ret += solve(1, i, (1 << i));
		ret %= MOD;
	}
	cout << ret << '\n';
}