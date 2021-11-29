#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

typedef pair<int, int> p;
int N, M;
vector<int> graph[MAX];
bool visited[MAX];
int cnt;
void dfs(int now) {
	visited[now] = true;
	for (int next : graph[now])
		if (!visited[next]) {
			cnt++;
			dfs(next);
		}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		graph[b].push_back(a);
	}
	vector<int> res;
	int max_cnt = -1;
	for (int i = 1; i <= N; ++i) {
		memset(visited, false, sizeof(visited));
		cnt = 0;
		dfs(i);
		if (cnt == max_cnt)
			res.push_back(i);
		else if (cnt > max_cnt) {
			max_cnt = cnt;
			res.clear();
			res.push_back(i);
		}

	}
	sort(res.begin(), res.end());
	for (int a : res)
		cout << a << " ";
	
	return 0;
}