#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
int numbers[101], strike[101], ball[101];
bool IsNumberOkay(int number) {
	vector<int> nb(3);
	for (int i = 0; i < 3; ++i) {
		nb[i] = number % 10;
		if (nb[i] == 0) return false;
		number /= 10;
	}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (i != j && nb[i] == nb[j])
				return false;
	return true;
}

int count_Strike(int number, int target) {
	int cnt = 0;
	for (int i = 0; i < 3; ++i) {
		if (number % 10 == target % 10)
			cnt++;
		number /= 10; target /= 10;
	}
	return cnt;
}

int count_Ball(int number, int target) {
	vector<int> nb(3);
	vector<int> tg(3);
	int cnt = 0;
	for (int i = 0; i < 3; ++i) {
		nb[i] = number % 10;
		tg[i] = target % 10;
		number /= 10; target /= 10;
	}

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			if (i != j && nb[i] == tg[j])
				cnt++;
		}
	return cnt;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i] >> strike[i] >> ball[i];
	}
	int res = 0, cnt = 0;
	for (int i = 123; i < 1000; ++i) {
		if (!IsNumberOkay(i)) continue;
		cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (strike[j] == count_Strike(i, numbers[j]) && ball[j] == count_Ball(i, numbers[j]))
				cnt++;
		}
		if (cnt == n) res++;
	}
	cout << res << endl;
}