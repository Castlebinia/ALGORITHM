#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
using ll = long long;

double ccw(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) {
	double temp = (double)(x1 * y2 + x2 * y3 + x3 * y1);
	temp -= (double)(y1*x2 + y2 * x3 + y3 * x1);
	return (temp / 2.);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<ll, ll>>p;
	for (int i = 0; i < n; i++) {
		ll x, y;
		scanf("%ld %ld", &x, &y);
		p.push_back({ x,y });
	}
	double ret = 0;
	for (int i = 0; i < n - 2; i++) {
		ret += ccw(p[0].first, p[i + 1].first, p[i + 2].first, p[0].second, p[i + 1].second, p[i + 2].second);
	}
	printf("%.1lf\n", abs(ret));
}