#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1000001
using namespace std;
typedef pair<int, int> p;

using namespace std;
int N; 
int numbers[MAX];
int answer[MAX] = {0,};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> numbers[i];

	stack<int> stk;
	for (int i = 0; i < N; ++i) {
		while (!stk.empty()&& numbers[stk.top()] < numbers[i]) {
			answer[stk.top()] = numbers[i];
			stk.pop();
		}
		stk.push(i);
	}

	// 오큰수 없음
	while (!stk.empty()) {
		answer[stk.top()] = -1;
		stk.pop();
	}

	for (int i = 0; i < N; ++i)
		cout << answer[i] << " ";

	return 0;
}