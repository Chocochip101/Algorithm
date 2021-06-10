#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
#define MOD 1000000000
using namespace std;
typedef pair<int, int> p;


string cache[101][101];

string bigInteger(string num1, string num2) {
	ll sum = 0;
	string result;

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}

		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string solve(int n, int k) {
	if (n == k || k == 0) return "1";

	string& ret = cache[n][k];
	if (ret != "") return ret;

	return ret = bigInteger(solve(n - 1, k - 1), solve(n - 1, k));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;
	cout << solve(n, k) << endl;
	return 0;
}