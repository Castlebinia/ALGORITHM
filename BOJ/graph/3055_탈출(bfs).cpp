#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int r, c;
bool outrange(int x, int y) {
	if (x < 0 || y < 0 || x >= r || y >= c)return true;
	return false;
}
bool check[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
char map[51][51];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)cin >> map[i];
	queue<pair<int, int>>mq;
	queue<pair<int, int>>wq;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'S') {
				mq.push({ i,j });
				check[i][j] = true;
			}
			else if (map[i][j] == '*') {
				wq.push({ i,j });
			}
		}
	}
	int ret = 0;
	bool fin = false;
	while (!mq.empty()) {
		ret++;
		int mqsize = mq.size();
		for (int i = 0; i < mqsize; i++) {
			int x = mq.front().first;
			int y = mq.front().second;
			mq.pop();
			if (map[x][y] == '*')continue;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if (map[nx][ny] == 'D') {
					fin = true;
					break;
				}
				if (outrange(nx, ny))continue;
				if (!check[nx][ny] && map[nx][ny] == '.') {
					check[nx][ny] = true;
					mq.push({ nx,ny });
				}
			}
			if (fin)break;
		}
		if (fin)break;
		int wqsize = wq.size();
		for (int i = 0; i < wqsize; i++) {
			int x = wq.front().first;
			int y = wq.front().second;
			wq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (outrange(nx, ny))continue;
				if (map[nx][ny] == '.') {
					map[nx][ny] = '*';
					wq.push({ nx,ny });
				}
			}
		}
	}
	if (fin)cout << ret << '\n';
	else cout << "KAKTUS\n";
}