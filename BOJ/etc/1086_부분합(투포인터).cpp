#include <iostream>
#include <algorithm>

const int inf = 987654231;

typedef long long ll;

using namespace std;

ll a[1000001];
ll s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int left, right, ans;
	left = right = 0;
	ans = inf;
	ll sum = a[left];
	while (left <= right && right < n) {
		if (sum < s) {
			right++;
			sum += a[right];
		}
		else if (sum == s) {
			ans = min(ans, (right - left + 1));
			right++;
			sum += a[right];
		}else if (sum > s) {
			ans = min(ans, (right - left + 1));
			sum -= a[left];
			left++;
			if (left > right && left < n) {
				right = left;
				sum = a[left];
			}
		}
	}
	cout << (ans == inf ? 0 : ans) << '\n';
}