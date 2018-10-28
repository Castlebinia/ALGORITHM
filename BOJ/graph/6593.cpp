#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = { 0,0,0,0,1,-1 };

using namespace std;
char map[31][31][31];
int check[31][31][31];

struct Point { int x, y, z; };

int main() {
	while (true) {
		int l, r, c, ex=0, ey=0, ez=0;
		cin >> l >> r >> c;
		if (!l && !r && !c)break;
		queue<Point>q;
		bool flag = false;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++){
				cin >> map[i][j];
				for (int k = 0; k < c; k++) {
					if (map[i][j][k] == 'S') {
						q.push({ i,j,k });
						check[i][j][k] = 1;
					}
				}
			}
			getchar();
		}
		while (!q.empty()) {
				auto now = q.front();
				int x = now.x;
				int y = now.y;
				int z = now.z;
				if (map[x][y][z] == 'E') {
					flag = true;
					cout << "Escaped in " << check[x][y][z]-1 << " minute(s).\n";
					break;
				}
				q.pop();
				for (int i = 0; i < 6; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					int nz = z + dz[i];
					if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c)continue;
					if (!check[nx][ny][nz] && map[nx][ny][nz] != '#') {
						check[nx][ny][nz] = check[x][y][z] + 1;
						q.push({ nx,ny,nz });
					}
				}
		}
		if (!flag)cout << "Trapped!\n";
	}
}