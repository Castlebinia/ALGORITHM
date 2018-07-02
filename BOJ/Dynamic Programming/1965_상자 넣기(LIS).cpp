#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int a[1001];
int d[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)d[i] = 1;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j])d[i] = max(d[i],d[j]+1);
		}
	}
	sort(d, d + n);
	cout << d[n-1] << '\n';
}