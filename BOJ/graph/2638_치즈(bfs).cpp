#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int a[101][101];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int check[101][101];
int cnt[101][101];
int n, m;

bool getout(int nx, int ny) {
	if (nx >= 0 && ny >= 0 && nx < n && ny < m)return true;
	return false;
}

void bfs(int x,int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	memset(check, false, sizeof(check));
	check[x][y] = true;
	while (!q.empty()) {
		int sx = q.front().first;
		int sy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if (getout(nx,ny)&&!check[nx][ny]&&a[nx][ny]!=1) {
				a[nx][ny] = -1;
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

bool fin() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1)return false;
		}
	}
	return true;
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
	int ret = 0;
	while (true) {
		if (fin()) {
			cout << ret << '\n';
			return 0;
		}
		bfs(0, 0);
		ret++;
		memset(cnt, 0, sizeof(cnt));
		for (int i =0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (getout(nx,ny)) {
							if (a[nx][ny] == -1)cnt[i][j]++;
						}
					}
					if (cnt[i][j] >= 2)a[i][j] = 0;
				}
				else continue;
			}
		}
	}
}