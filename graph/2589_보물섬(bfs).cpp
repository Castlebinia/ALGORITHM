#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

char a[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int d[51][51];
int n, m;
bool check[51][51];
int ret;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	d[x][y] = 1;
	check[x][y] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && a[nx][ny] == 'L') {
				if (!check[nx][ny]) {
					check[nx][ny] = true;
					q.push({ nx,ny });
					d[nx][ny] = d[now.first][now.second] + 1;
					if (d[nx][ny] > ret)ret = d[nx][ny];
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;
	cin.get();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1c", &a[i][j]);
		}
		cin.get();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(check, false, sizeof(check));
			memset(d, 0, sizeof(d));
			if (a[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}
	cout << ret-1 << '\n';
}