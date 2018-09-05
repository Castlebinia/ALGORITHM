#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
int n;
int a[3][150001], d[3][150001][1<<3];

int solve(int person, int pos, int visit) {
	if (pos == n) {
		if (visit == 7)return 0;
		return INF;
	}
	int &ret = d[person][pos][visit];
	if (ret != -1)return ret;
	ret = a[person][pos] + solve(person, pos + 1, visit | (1 << person));
	for (int i = 0; i < 3; i++){
		if ((1 << i)&visit)continue;
		ret = min(ret, a[person][pos] + solve(i, pos+1, visit | (1 << person)));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < n; j++)cin >> a[i][j];
	memset(d, -1, sizeof(d));
	int ret = INF;
	for (int i = 0; i < 3; i++) ret = min(ret, solve(i, 0, 0));
	cout << ret << '\n';
}