#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	cin >> n;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += (int)(s[i] - '0');
	cout << sum;
	return 0;
}