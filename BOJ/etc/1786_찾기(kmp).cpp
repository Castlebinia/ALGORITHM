#include <iostream>
#include <vector>
#include <string>

using namespace std;

int fail[1000001];

int main() {
	string T, P;
	getline(cin, T);	getline(cin, P);
	int M = P.size();	int N = T.size();
	for (int i = 1, j = 0; i < M; i++) {
		while (j > 0 && P[i] != P[j])j = fail[j - 1];
		if (P[i] == P[j])fail[i] = ++j;
	}
	vector<int>result;
	for (int i = 0, j = 0; i < N; i++) {
		while (j > 0 && T[i] != P[j])j = fail[j - 1];
		if (T[i] == P[j]) {
			if (j == M - 1) {
				result.push_back(i - M + 2);
				j = fail[j];
			}
			else j++;
		}
	}
	cout << result.size() << '\n';
	for (auto x : result)cout << x << ' ';
	cout << '\n';
}
