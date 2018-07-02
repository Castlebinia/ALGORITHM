#include <iostream>
#include <algorithm>

using namespace std;
const int inf = 0x3f3f3f3f;

int d[1001][1001];
int a[1001][1001];
int m, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	int ret = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) {
				int tmp = min({ inf,d[i - 1][j - 1],d[i - 1][j],d[i][j - 1] });
				d[i][j] = (tmp == inf) ? 1 : tmp + 1;
				ret = max(ret, d[i][j]);
			}
		}
	}
	cout << ret << '\n';
}

