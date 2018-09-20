#include <iostream>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool map[5][5], visited[5][5];
int k, apple, ret;

bool range(int x, int y) {
	return (x >= 0 && y >= 0 && x < 5 && y < 5);
}

void foo(int cnt, int x,int y) {
	if (cnt == apple) {
		if (x==4&&y==4)ret++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!range(nx, ny) || map[nx][ny]||visited[nx][ny])continue;
		visited[nx][ny] = true;
		foo(cnt + 1, nx,ny);
		visited[nx][ny] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	apple = 5 * 5 - k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		map[x][y] = true;
	}
	visited[0][0] = true;
	foo(1, 0, 0);
	cout << ret << '\n';
}