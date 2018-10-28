#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[1001][1001];
int n, m;
bool check[1001][1001];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool edge(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)return true;
	else return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin >> m >> n;
		for (int i = 0; i < n; i++) cin >> map[i];
		memset(check, false, sizeof(check));
		int ret = 0;
		bool fin = false;
		queue<pair<int, int>>sq;
		queue<pair<int, int>>fq;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '@') {
					sq.push({ i,j });
					check[i][j] = true;
				}
				if (map[i][j] == '*') {
					fq.push({ i,j });
				}
			}
		}
		while (!sq.empty()) {
			ret++;
			int sqsize = sq.size();
			for (int i = 0; i < sqsize; i++) {
				int x = sq.front().first;
				int y = sq.front().second;
				sq.pop();
				if (map[x][y] == '*')continue;
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (edge(nx, ny)) {
						fin = true;
						break;
					}
					if (!check[nx][ny] && map[nx][ny] == '.') {
						check[nx][ny] = true;
						sq.push({ nx,ny });
					}
					if (fin)break;
				}
				if (fin)break;
			}
			if (fin)break;
			int fqsize = fq.size();
			for (int k = 0; k < fqsize; k++) {
				int x = fq.front().first;
				int y = fq.front().second;
				fq.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (edge(nx, ny))continue;
					if (map[nx][ny] == '.') {
						map[nx][ny] = '*';
						fq.push({ nx,ny });
					}
				}
			}
		}
		if (fin)cout << ret << '\n';
		else cout << "IMPOSSIBLE\n";
	}
}
