#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int a[502][502];
int dp[502][502];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
 
int foo(int x, int y) {
	if (x == n-1 && y == m-1)return 1;
	if (dp[x][y]!=-1)return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (a[x][y] > a[nx][ny])dp[x][y] += foo(nx, ny);
		}
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << foo(0, 0) << '\n';
}