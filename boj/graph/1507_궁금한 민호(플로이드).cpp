#include <iostream>

using namespace std;

int d[21][21];
bool check[21][21];
int ret;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				for (int k = 0; k < n; k++) {
					if (k == i)continue;
					if (k == j)continue;
					if (d[i][j] > d[i][k] + d[k][j]) {
						cout << -1 << '\n';
						return 0;
					}
					if (d[i][j] == d[i][k] + d[k][j])check[i][j] = true;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					ret += d[i][j];
				}
			}
		}
		cout << ret/2 << '\n';
	
}
