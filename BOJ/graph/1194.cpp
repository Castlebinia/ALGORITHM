#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
struct P {
	int x, y, k;
};

bool outrange(int x, int y) {return !(x >= 0 && y >= 0 && x < n && y < m);}

bool small(char c) {return (c >= 'a'&&c <= 'f');}

bool big(char c) {return (c >= 'A'&&c <= 'F');}

using namespace std;

string map[50];
bool check[50][50][1<<7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> map[i];
	queue<P>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '0') {
				q.push({ i,j,0 });
				check[i][j][0] = true;
			}
		}
	}
	int ret = 0;
	while (!q.empty()){
	int qsize = q.size();
	for (int i = 0; i < qsize; i++) {
		auto now = q.front();
		if (map[now.x][now.y] == '1') {
			cout << ret << '\n';
			return 0;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			int key = now.k;
			if (outrange(nx, ny) || map[nx][ny] == '#')continue;
			char c = map[nx][ny];
			if (small(c)) {
				if (check[nx][ny][key])continue;
				key |= (1 << (c - 'a'));
			}
			if (big(c)) {
				if (!(key&(1 << (c - 'A')))||check[nx][ny][key])continue;
			}
			if (!check[nx][ny][key]) {
				check[nx][ny][key] = true;
				q.push({ nx,ny,key });
			}

		}
	}
	ret++;
	}
	cout << -1 << '\n';
}