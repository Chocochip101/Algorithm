#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 501
#define MOD 1000000000
#define PI 3.1415926254
using namespace std;
typedef pair<int, int> p;
int n;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if (n % 2 == 0)
		cout << "CY" << endl;
	else
		cout << "SK" << endl;
	return 0;
}