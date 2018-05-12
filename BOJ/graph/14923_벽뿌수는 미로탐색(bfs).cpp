#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Point{
public:
	int x, y, crush;
	Point(int ix, int iy, int icrush) {
		x = ix;
		y = iy;
		crush = icrush;
	}
};

int n, m;
bool fin;
bool visit[1000][1000][2] = { false, };
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int a[1000][1000];
int ans[1000][1000][2];

void bfs(int startx,int starty,int goalx,int goaly) {
	queue<Point> q;
	q.push(Point(startx, starty, 1));
	visit[startx][starty][1] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		if (x == goalx - 1 && y==goaly-1) {
			cout << max(ans[x][y][0],ans[x][y][1]) << '\n';
			fin = true;
			return;
		}
		int crush = q.front().crush;
		q.pop();
		if (crush == 1) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
					if (!visit[nx][ny][1]) {
						if (a[nx][ny] == 0) {
							visit[nx][ny][1] = true;
							q.push(Point(nx, ny, 1));
							ans[nx][ny][1] = ans[x][y][1] + 1;
						}
						else if (a[nx][ny] == 1) {
							visit[nx][ny][0] = true;
							q.push(Point(nx, ny, 0));
							ans[nx][ny][0] = ans[x][y][1] + 1;
						}
					}
				}
			}
		}
		else if (crush == 0) {
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
					if (!visit[nx][ny][0] && a[nx][ny] == 0) {
						visit[nx][ny][0] = true;
						q.push(Point(nx, ny, 0));
						ans[nx][ny][0] = ans[x][y][0] + 1;
					}
				}
			}
		}
	}
}


int main() {
	int sx, sy, gx, gy;
	cin >> n >> m;
	cin >> sx >> sy >> gx >> gy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	bfs(sx-1,sy-1,gx,gy);
	if (!fin)cout << -1 << '\n';
}