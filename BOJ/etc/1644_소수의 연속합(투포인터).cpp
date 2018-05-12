#include <iostream>

using namespace std;

int p[3000000];
bool check[4000001];
int pn;

int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
			for (int j = i * 2; j<= n; j += i) {
				if (!check[j]) {
					check[j] = true;
				}
			}
	}
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			p[pn++] = i;
		}
	}
	int left, right, ans,sum;
	left = right = ans = 0;
	sum = p[left];
	while (left <= right && right < pn) {
		if (sum < n) {
			right++;
			sum += p[right];
		}
		else if (sum == n) {
			right++;
			sum += p[right];
			ans++;
		}
		else if (sum > n) {
			sum -= p[left];
			left++;
			if (left > right && left < n) {
				right = left;
				sum = p[left];
			}
		}
	}
	cout << ans << '\n';
}