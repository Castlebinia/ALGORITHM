#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int a[3000001+3001];
int check[3001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = n; i < n + k; i++)a[i] = a[i - n];
	int tmp = 1;
	check[c] = 1;
	int ret = 0;
	for (int i = 0; i < k-1; i++) {
		if (!check[a[i]]) tmp++;
		check[a[i]]++;
	}
	for (int left=0,right=k-1;right<n+k;left++,right++){
		if (!check[a[right]]) tmp++;
		check[a[right]]++;
		ret=max(ret,tmp);
		check[a[left]]--;
		if (!check[a[left]])tmp--;	
	}
	cout << ret << '\n';
}