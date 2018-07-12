#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[501][501];
int ans[501][501];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;

int foo(int i, int j) {
	if (ans[i][j] != 1)return ans[i][j];
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx < n&&ny<n&&nx>=0&&ny>=0 &&a[i][j]<a[nx][ny])
		ans[i][j] = max(ans[i][j], foo(nx, ny)+1);
	}
	return ans[i][j];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			ans[i][j] = 1;
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret = max(ret,foo(i,j));
		}
	}
	cout << ret << '\n';
}