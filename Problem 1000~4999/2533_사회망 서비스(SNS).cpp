#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 1000001
using namespace std;
typedef pair<int, int> p;

int N;
vector<int> graph[MAX];
vector<int> oneWay[MAX];
int cache[MAX][2];
bool visited[MAX];

void dfs(int now) {
	visited[now] = true;

	for(int next: graph[now])
		if (!visited[next]) {
			oneWay[now].push_back(next);
			dfs(next);
		}
}

int solve(int now, int flag) {
	int& ret = cache[now][flag];
	if (ret != -1) return ret;

	if (flag == 0) {
		ret = 1;
		for (int next : oneWay[now])
			ret += min(solve(next, 0), solve(next, 1));
	}
	else {
		ret = 0;
		for (int next : oneWay[now])
			ret += solve(next, 0);
	}
	return ret;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(visited, false, sizeof(visited));
	memset(cache, -1, sizeof(cache));

	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	cout << min(solve(1, 0), solve(1, 1)) << endl;
	return 0;
}