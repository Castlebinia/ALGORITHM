#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int a[200001];
bool check[200001];
int n, ret;

void go(int node) {
	if (node * 2 <= n) {
		a[node*2] = ++ret;
		check[ret] = true;
		go(node * 2);
	}
	if (node * 2 + 1 <= n) {
		a[node*2+1] = ++ret;
		check[ret] = true;
		go(node * 2 + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, p;
	cin >> n >> k >> p;
	int tmp = k;
	ret = k;
	for (int i = p; i >1; i /= 2) {
		a[i/2] = --tmp;
		check[tmp] = true;
	}
	if (tmp < 1) {
		cout << -1 << '\n';
		return 0;
	}
	int left = tmp;
	go(p);
	if (ret > n) {
		cout << -1 << '\n';
		return 0;
	}
	a[p] = k;
	check[k] = true;
	int j = 1;
	for (int i = 1; i <= n; i++) {
		if (!a[i]) {
			while (check[j])j++;
			a[i] = j;
			check[j] = true;
		}
	}
	for (int i = 1; i <= n; i++)cout << a[i] << '\n';
}