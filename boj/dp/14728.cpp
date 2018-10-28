#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int, int>>p;
int d[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int time, value;
		cin >> time >> value;
		for (int i = k; i >= time; i--) {
			d[i] = max(d[i], d[i - time] + value);
		}
	}
	cout << d[k] << '\n';
}