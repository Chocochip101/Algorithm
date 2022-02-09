#include <bits/stdc++.h>
#define endl "\n"
#define MAX  101
using namespace std;
typedef pair<int, int> p;

int n, m;
//사다라 or 계단
int go[MAX];
int board[MAX];

void Init() {
	for (int i = 0; i < MAX; ++i)
		go[i] = i;
	memset(board, -1, sizeof(board));
}

void bfs() {
	queue<int> q;
	q.push(go[1]);
	board[1] = 0;
	board[go[1]] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 1; i <= 6; ++i) {
			int next = now + i;
			if (next > 100) continue;
			next = go[next];
			if (board[next] == -1) {
				board[next] = board[now] + 1;
				q.push(next);
			}
		}

	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	Init();
	for (int i = 0; i < n + m; ++i) {
		int a, b; cin >> a >> b;
		go[a] = b;
	}
	bfs();
	cout << board[100] << endl;
	return 0;
}