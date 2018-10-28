#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int map[101][101];
bool check[101][101];
int num = 0;
int n;
int name[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int d[101][101];
int ret = 0x3f3f3f3f;

void dfs(int x, int y) {
	check[x][y] = true;
	for(int i=0;i<4;i++){
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
		if (!check[nx][ny]&&map[nx][ny]==1) {
			name[nx][ny] = name[x][y];
			check[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}
void naming() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]==1&&!check[i][j]) {
				name[i][j] = ++num;
				dfs(i, j);
			}
		}
	}
}

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	naming();
	memset(d, -1, sizeof(d));
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				q.push({ i,j });
				d[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (d[nx][ny] == -1) {
				d[nx][ny] = d[x][y] + 1;
				name[nx][ny] = name[x][y];
				q.push({ nx,ny });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
				if(name[i][j]!=name[nx][ny])
					ret = min(ret, d[i][j] + d[nx][ny]);
			}
		}
	}
	cout << ret << '\n';
}
