#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 1,-1,0,0,0,0 };

struct Point {
	int x, y, z;
	Point(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

int ret;
int m,n,l;
int a[101][101][101];
bool check[101][101][101];
int d[101][101][101];

bool fin() {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (a[i][j][k] == 0)return false;
			}
		}
	}
	return true;
}
void bfs() {
	queue<Point>q;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (a[i][j][k] == 1) {
					q.push(Point(i,j,k));
					check[i][j][k] = true;
				}
			}
		}
	}
	while(!q.empty()){
		for (int i = 0; i < q.size(); i++) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= m || nz >= n)continue;
				if (!check[nx][ny][nz] && a[nx][ny][nz] == 0) {
					check[nx][ny][nz] = true;
					a[nx][ny][nz] = 1;
					q.push(Point(nx, ny, nz));
					ret=d[nx][ny][nz] = d[x][y][z] + 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> l;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				cin >> a[i][j][k];
			}
		}
	}
	if (fin()) {
		cout << 0 << '\n';
		return 0;
	}
	bfs();
	if (fin()) {
		cout << ret << '\n';
		return 0;
	}
	cout << -1 << '\n';
}