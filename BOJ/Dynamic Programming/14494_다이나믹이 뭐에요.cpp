#include <iostream>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll d[1002][1002];

int main() {
	int n, m;
	cin >> n >> m;
	d[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = d[i - 1][j - 1]%mod + d[i - 1][j]%mod + d[i][j - 1]%mod;
			d[i][j] %= mod;
		}
	}
	cout << d[n][m] << '\n';
}