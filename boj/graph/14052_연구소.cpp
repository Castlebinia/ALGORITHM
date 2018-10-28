#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int map[9][9];	//입력받는 배열
int vi[9][9]; // 바이러스 퍼졌을 때
bool check[9][9];
int ret = 0;


void bfs() {
	memset(check, false, sizeof(check));
	queue<pair<int, int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vi[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vi[i][j] == 2) {
				q.push({ i,j });
				check[i][j] = true;
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
			if (nx < n && ny < m && nx >= 0 && ny >= 0 && vi[nx][ny] == 0) {
				if (!check[nx][ny]) {
					check[nx][ny] = true;
					vi[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void foo(int cnt) {
	int vcnt = 0;
	if (cnt == 3) {
		bfs();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vi[i][j] == 0)vcnt++;
			}
		}
		ret = max(ret, vcnt);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					foo(cnt + 1);
					map[i][j] = 0;	//원상복구(모든 경우 보려고)
				}
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	foo(0);
	cout << ret << '\n';
}