#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int n;
int max_num;
vector<int> numbers;
bool isPrime[1010];
void eratos() {
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(max_num));
	for (int i = 2; i <= sqrtn; ++i)
		if (isPrime[i])
			for (int j = i * i; j <= max_num; j += i)
				isPrime[j] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	numbers.resize(n);
	for (int i = 0; i < n; ++i)cin >> numbers[i];
	max_num = *max_element(numbers.begin(), numbers.end());
	memset(isPrime, 1, sizeof(isPrime));
	eratos();
	int res = 0;
	for (int i = 0; i < n; ++i)
		if (isPrime[numbers[i]]) res++;
	cout << res << endl;
	return 0;
}
