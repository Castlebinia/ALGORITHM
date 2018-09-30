#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int map[1001][1001];
int tmap[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)tmap[i][j] = map[i][j];
	}
	for (int i = 2; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j < i; j++) 
			sum += map[i][j];
		if (!sum || sum == i - 1) {
			if (!map[i][1]) {
				for (int j = 1; j <= n; j++) {
					map[i][j] = 1 - map[i][j];
					map[j][i] ^= 1;
				}
			}
		}
		else break;
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ret += map[i][j];
		}
	}
	if (ret == n * n - n) {
		cout << "DA\n"; return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)map[i][j] = tmap[i][j];
	}
	for (int i = 2; i <= n; i++) {
		map[i][1] = 1 - map[i][1];
		map[1][i] = 1 - map[1][i];
	}
	for (int i = 2; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j < i; j++)
			sum += map[i][j];
		if (!sum || sum == i - 1) {
			if (!map[i][1]) {
				for (int j = 1; j <= n; j++) {
					map[i][j] = 1 - map[i][j];
					map[j][i] ^= 1;
				}
			}
		}
		else break;
	}
	ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ret +=map[i][j];
		}
	}
	if (ret == n * n - n) {
		cout << "DA\n"; return 0;
	}
	cout << "NE\n";
}

