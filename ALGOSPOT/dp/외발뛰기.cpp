#include <iostream>
#include <cstring>

int a[101][101];
int d[101][101];
using namespace std;

bool foo(int x, int y, int n) {
	if (x >= n || y >= n)return false;
	if (x == n - 1 && y == n - 1)return true;
	int& ret = d[x][y];
	if (ret!=-1)return ret;
	return ret = foo(x + a[x][y], y, n) || foo(x, y + a[x][y],n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(d, -1, sizeof(d));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		if (foo(0, 0, n))cout << "YES\n";
		else cout << "NO\n";
	}
}