#include <iostream>

using namespace std;

using ll = long long;

const ll mod = 1000000007;
ll d[1000001];

ll foo(ll x, int n) {
	if (n == 0)return 1;
	if (n % 2 != 0) {
		return (x * foo(x,n - 1))%mod;
	}
	else {
		ll tmp = foo(x, n / 2);
		return (tmp * tmp)%mod;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	d[0] = 1;
	for (int i = 1; i <= 1000000; i++) {
		d[i] = (d[i - 1] * i)%mod;
	}
	cout << (d[n]*(foo((d[m]*d[n - m])%mod, mod - 2)))%mod << '\n';
} 
