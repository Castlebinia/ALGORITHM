#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

char a[101][101];
int n;
bool check[101][101];
void bfs(int x,int y) {
	check[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= n || ny >= n || nx < 0 || ny < 0)continue;
				if (a[nx][ny] == a[x][y]&&!check[nx][ny]) {
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin.get();
	for (int i = 0; i < n; i++) {
			cin >> a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'R')a[i][j] = 'G';
		}
	}
	cnt = 0;
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}