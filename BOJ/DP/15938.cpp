#include <iostream>
#include <cmath>
using namespace std;

using ll = long long;

ll d[401][401][201];
bool check[401][401];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int sx, sy, ex, ey, t,n;
	cin >> sx >> sy >> t >> ex >> ey>>n;
	int difx = t - sx, dify = t - sy;
	int tt = 2 * t;
	if (ex+difx>tt||ex+difx<0||ey+dify>tt||ey+dify<0) {
		cout << 0 << '\n';
		return 0;
	}
	ex += difx, ey += dify;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a + difx <= tt && b + dify <= tt &&a + difx >= 0 && b + dify >= 0) 
			check[a + difx][b + dify] = true;
	}
	d[t][t][0] = 1;
	long long ret = 0;
	for (int k = 1; k <=t; k++) {
		for (int i = 0; i < tt; i++) {
			for (int j = 0; j < tt; j++) {
				if (abs(i-t)+abs(j-t)>t)continue;
				if (i == ex && j == ey)continue;
				if (check[i][j]) continue;
				for (int x = 0; x < 4; x++) {
					int nx = i + dx[x];
					int ny = j + dy[x];
					if (nx < 0 || ny < 0 || nx>2 * t || ny>2 * t || check[nx][ny])continue;
					d[nx][ny][k] += d[i][j][k - 1] % MOD;
				}
			}
		}
		ret += d[ex][ey][k] % MOD;
	}
	cout << ret % MOD << '\n';
}