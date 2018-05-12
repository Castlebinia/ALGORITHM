#include <iostream>

using namespace std;

typedef long long ll;

ll a[10001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	ll k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int left, right;
	left = right = 0;
	ll ans = 0;
	ll sum = a[left];
	while (left <= right && right < n) {
		if (sum < k) {
			right++;
			sum += a[right];
		}
		else if (sum == k) {
			right++;
			ans++;
			sum += a[right];
		}
		else if (sum > k) {
			sum -= a[left];
			left++;
			if (left > right && left < n) {
				right = left;
				sum = a[left];
			}
		}
	}
	cout << ans << '\n';
}