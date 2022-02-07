#include <bits/stdc++.h>
#define INF 987654321
#define MAX 32001
#define ll long long
using namespace std;
typedef pair<int, int> p;

int N, M;
int indegree[MAX];
vector<int> graph[MAX];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= N; ++i)
		if (indegree[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int now = q.top(); q.pop();
		cout << now << " ";
		for (int next : graph[now]) {
			if (!(--indegree[next]))
				q.push(next);
		}
	}
	return 0;

}