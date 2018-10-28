#include <iostream>
#include <cstring>

using namespace std;
int a[102];
bool check[102];
bool check2[102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int ret = 0;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	int idx = 0;
	for (int i = 0; i < k; i++) {
		if (check[a[i]])continue;
		if (idx < n) {
			idx++;
			check[a[i]] = true;
			continue;
		}
		else{
			memset(check2, false, sizeof(check2));
			int ti =0;
			for (int j = i + 1; j < k; j++) {
				if (check[a[j]]&&!check2[a[j]]) {
					check2[a[j]] = true;
					ti = a[j];
				}
			}
			for (int j = 0; j < i; j++) {
				if (check[a[j]] && !check2[a[j]]) {
					ti = a[j];
				}
			}
			check[ti] = false;
			check[a[i]] = true;
			ret++;
		}
	}
	cout << ret << '\n';
}