#include <iostream>

using namespace std;

int d[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= 100; i++) {
		for (int j = i; j <= 100; j+=i) {
			d[j] = 1 - d[j];
		}
	}
	for (int i = 1; i <= 100; i++)d[i] += d[i - 1];
	while (t--) {
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}
}