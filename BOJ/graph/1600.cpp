#include <iostream>
#include <queue>

using namespace std;

int map[202][202];
bool check[202][202][32];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ddx[] = { 2,2,-2,-2,1,1,-1,-1 };
int ddy[] = { 1,-1,1,-1,2,-2,2,-2 };
int d[201][201][31];

struct P {
	int x, y, k;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt, n, m;
	cin >> cnt >> m >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];
	queue<P>q;
	int ret = -1;
	q.push({ 0,0,0 });
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		int x = now.x, y = now.y, k = now.k;
		if (x == n - 1 && y == m - 1) {
			ret = d[x][y][k];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (!check[nx][ny][k] && !map[nx][ny]) {
				check[nx][ny][k] = true;
				d[nx][ny][k] = d[x][y][k] + 1;
				q.push({ nx,ny,k });
			}
		}
		if (k == cnt)continue;
		for (int i = 0; i < 8; i++) {
			int nx = x + ddx[i];
			int ny = y + ddy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (!check[nx][ny][k + 1] && !map[nx][ny]) {
				check[nx][ny][k + 1] = true;
				d[nx][ny][k + 1] = d[x][y][k] + 1;
				q.push({ nx,ny,k + 1 });
			}
		}
	}
	cout << ret << '\n';
}