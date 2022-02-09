#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int factorial(int n) {
	if (n == 0 || n == 1) return 1;
	return n * factorial(n - 1);
}
int n, k;
int main() {
	cin >> n >> k;
	cout << factorial(n) / (factorial(n - k) * factorial(k));
	return 0;
}