#include <iostream>
#include <algorithm>

using namespace std;
int d[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	while (n--) {
		int t, v;
		cin >> t >> v;
		for (int i = k; i >= t; i--) {
			d[i] = max(d[i], d[i - t] + v);
		}
	}
	cout << d[k] << '\n';
}