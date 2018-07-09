#include <iostream>
#include <cstring>

using namespace std;
int mod = 1000000003;

int d[1001][1001];


int main() {
	int n, k;
	cin >> n >> k;
	d[4][1] = 4;
	d[4][2] = 2;
	d[3][1] = 3;
	for (int i = 5; i <= n; i++) {
		d[i][1] = i;
		if (i % 2 == 0) {
			d[i][i / 2] = 2;
		}                          
		for (int j = 2;; j++) {
			if (j > i / 2)break;
			d[i][j] = d[i - 1][j] % mod + d[i - 2][j - 1] % mod;
			d[i][j] %= mod;
		}
	}                                                                                                                                                                                                                                                            
	cout << d[n][k] << '\n';
}