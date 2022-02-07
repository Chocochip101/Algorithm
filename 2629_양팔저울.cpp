#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 31
using namespace std;


int N, M;
int chu[MAX];
int weight[MAX];
int cache[MAX][MAX * 501];
void solve(int idx, int total) {
	if (idx > N) return;

	int& ret = cache[idx][total];
	if (ret != -1) return;


	cache[idx][total] = 1;
	solve(idx + 1, total + chu[idx]);
	solve(idx + 1, total);
	solve(idx + 1, abs(total - chu[idx]));

	return;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	memset(cache, -1, sizeof(cache));
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> chu[i];
	cin >> M;
	for (int i = 0; i < M; ++i)
		cin >> weight[i];

	solve(0, 0);
	for (int i = 0; i < M; ++i) {
		if (weight[i] > (N + 1) * 501)
			cout << "N" << " ";
		else {
			if (cache[N][weight[i]] == 1)
				cout << "Y" << " ";
			else 
				cout << "N" << " ";
		}
	}
	return 0;
}