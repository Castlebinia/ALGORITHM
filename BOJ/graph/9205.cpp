#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int map[103][103];

struct P {
	int x, y;
};

bool foo(int x1, int x2, int y1, int y2) {
	if ((abs(x1 - x2) + abs(y1- y2)) <= 1000)return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(map, 0, sizeof(map));
		vector<P>p;
		int x, y;
		for (int i = 0; i < n + 2; i++) {
			cin >> x >> y;
			p.push_back({ x,y });
		}
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				if (foo(p[i].x, p[j].x, p[i].y, p[j].y))map[i][j] = map[j][i] = 1;
			}
		}
		for (int k = 0; k < n + 2; k++) {
			for (int i = 0; i < n + 2; i++) {
				for (int j = 0; j < n + 2; j++) {
					if (map[i][k] && map[k][j])map[i][j] = map[j][i] = 1;
				}
			}
		}
		if (map[0][n + 1])cout << "happy\n";
		else cout << "sad\n";
	}
}