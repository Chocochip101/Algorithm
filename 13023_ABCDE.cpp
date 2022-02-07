#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 2001
using namespace std;
typedef pair<int, int> p;

int N, M;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int now, int cnt) {
	visited[now] = true;
	if (cnt >= 4) {
		cout << 1;
		exit(0);
	}
	for (int next : graph[now]) 
		if (!visited[next])
			dfs(next, cnt + 1);
	
	visited[now] = false;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < N; ++i) {
		dfs(i, 0);

	}
	cout << 0;
	return 0;
}