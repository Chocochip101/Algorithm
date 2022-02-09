#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define INF 987654321
#define MOD 1001
using namespace std;
typedef pair<int, int> p;


int N, M;
bool board[MAX][MAX];
int indegree[MAX];
int semester[MAX];
void bfs() {
	queue<p> q;
	for (int i = 1; i <= N; ++i)
		if (indegree[i] == 0)
			q.push({ i, 1 });

	vector<int> res;
	while (!q.empty()) {
		int idx = q.front().first;
		int sem = q.front().second;
		q.pop();
		semester[idx] = sem;
		for (int i = 1; i <= N; ++i) {
			if (board[idx][i]) {
				--indegree[i];
				if (indegree[i] == 0) {
					q.push({ i, sem + 1 });
				}
			}
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(board, false, sizeof(board));
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		indegree[b]++;
		board[a][b] = true;
	}
	bfs();
	for (int i = 1; i <= N; ++i)
		cout << semester[i] << " ";
	return 0;
}