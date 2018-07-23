#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int d[300001];
int d2[300001];
int dp[300001];
const int INF = 0x3f3f3f3f;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= 300000; i++) 
		d[i] = d[i - 1] + i;
	for (int i = 1; i <= 300000; i++) 
		d2[i] = d2[i-1] + d[i];
	for (int i = 1; i <= 300000; i++)dp[i] = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 123; j++) {
			if (i >= d2[j]) {
				dp[i] = min(dp[i - d2[j]]+1, dp[i]);
			}
		}
	}
	cout << dp[n] << '\n';	
}