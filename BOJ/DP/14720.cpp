#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int d[1001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	if(!a[0])d[0][0] = 1;
	for (int i = 1; i < n; i++) {
		d[i][0] = (a[i] == 0) ? d[i - 1][2] + 1 : d[i - 1][0];
		d[i][1] = (a[i] == 1 && d[i][0] > 0) ? d[i - 1][0] + 1 : d[i - 1][1];
		d[i][2] = (a[i] == 2 && d[i][1] > d[i][0]) ? d[i - 1][1] + 1 : d[i - 1][2];
	}
	cout << max({ d[n - 1][0],d[n - 1][1],d[n - 1][2] }) << '\n';
}