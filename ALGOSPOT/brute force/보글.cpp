#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[] = {1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };

char a[6][6];
int d[6][6];

bool foo(int x, int y,string s,int n) {
	if (a[x][y] != s[0]) {
		return false;
	}
	if (s.length() == 1)return true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= n && ny <= n)
			if (foo(nx, ny, s.substr(1), n))return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	cin.get();
	while (t--) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				scanf("%1c", &a[i][j]);
			}
			cin.get();
		}
		int n;
		cin >> n;
		vector<string>p(n+1);
		for (int k = 1; k <=n; k++) {
			memset(d, -1, sizeof(d));
			bool flag = false;
			cin >> p[k];
			cout << p[k] << ' ';
			for (int i = 1; i <= 5; i++) {
				for (int j = 1; j <= 5; j++) {
					if (foo(i, j, p[k], 5)==1) {
						cout << "YES\n";
						flag = true;
						break;
					}
				}
				if (flag)break;
			}
			if (!flag)cout << "NO\n";
		}
	}
}