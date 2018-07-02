#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool check[301][301];
int map[301][301];
int tmap[301][301];
int n, m;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
		if (!check[nx][ny] && map[nx][ny]>0) {
			check[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int foo(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[nx][ny] <= 0)cnt++;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ret = 0;
	while (true) {
		memset(check, false, sizeof(check));
		int com = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!check[i][j] && map[i][j] > 0) {
					com++;
					dfs(i, j);
					if (com >= 2) {
						cout << ret << '\n';
						return 0;
					}
				}
			}
		}
		if (com == 0) {
			cout << "0\n";
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmap[i][j] = map[i][j] - foo(i, j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = tmap[i][j];
			}
		}
		ret++;
	}
}