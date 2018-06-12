#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = { 1,-1,0,0,0 };
int dy[] = { 0,0,-1,1,0 };
const int INF = 0x3f3f3f3f;

int a[19][19];
int b[19][19];
int n;

bool off() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1)return false;
		}
	}
	return true;
}

void Swap(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < n && ny < n && nx >= 0 && ny >= 0) {
			a[nx][ny] = 1 - a[nx][ny];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ret = INF;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < (1<<n); i++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = b[i][j];
			}
		}
		for (int j = 0; j < n; j++) {
			if (i&(1 << j)) {
				Swap(0, j);
				cnt++;
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i-1][j] == 1) {
					Swap(i, j);
					cnt++;
				}
			}
		}
		if (!off())cnt = INF;
		ret = min(ret, cnt);
	}
	if (ret == INF)ret = -1;
	cout << ret << '\n';
}