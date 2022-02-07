#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define MAX 5000001
#define value first
#define index second
using namespace std;
typedef pair<int, int> p;

int n, l;
deque<p> opl;
int numbers[MAX];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> n >> l;


	loop(i, n) {
		cin >> numbers[i];

		if (!opl.empty() && opl.front().index <= i - l)
			opl.pop_front();

		while (!opl.empty() && opl.back().value > numbers[i])
			opl.pop_back();

		opl.push_back({ numbers[i],i });
		cout << opl.front().value << " ";
	}
	return 0;
}