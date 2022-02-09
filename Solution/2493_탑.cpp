#include <bits/stdc++.h>
#define INF 987654321
#define MAX 500001

using namespace std;
typedef pair<int, int> p;

int N, numbers[MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N; 
	for (int i = 1; i <= N; ++i)
		cin >> numbers[i];

	vector<int> answer(N + 1);
	stack<int> s;

	for (int i = N; i >= 1; --i) {
		while (!s.empty()&& numbers[s.top()] <= numbers[i]) {
			answer[s.top()] = i;
			s.pop();
			
		}
		s.push(i);
	}

	while (!s.empty()) {
		answer[s.top()] = 0;
		s.pop();
	}

	for (int i = 1; i <= N; ++i)
		cout << answer[i] << " ";
	return 0;
}