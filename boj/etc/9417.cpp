#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int gcd(int a,int b){return b?gcd(a,a%b):a;}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		string s;
		getline(cin,s);
		istringstream iss(s);
		string sub;
		iss>>sub;
		int a=stoi(sub);
		int ret=a;
		while(iss){
			string sub;
			iss>>sub;
			int tmp=stoi(sub);
			ret=gcd(ret,tmp);
		}
		cout << ret << '\n';
	}
}
