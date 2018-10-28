#include <iostream>
#include <algorithm>

using namespace std;

char map[60][60];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int ret = 64;
	for (int i = 0; i < n; i++)cin >> map[i];
	for (int i = 0; i <= n-8; i++) {
		for (int j = 0; j <= m-8; j++) {
			int cnt = 0;
			for (int r = 0; r < 8; r++) {
				for (int c = 0; c < 8; c++) {
					char tmp = (r % 2 == c % 2) ? 'W' : 'B';
					if (map[i + r][j + c] != tmp)cnt++;
				}
			}
			ret = min({ ret,cnt,64 - cnt });
		}
	}
	cout << ret << '\n';
}