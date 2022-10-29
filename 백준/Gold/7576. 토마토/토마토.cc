#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
using namespace std;
typedef pair<int, int> p;
int n, m;
int board[1001][1001];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	cin >> m >> n;
	queue<p> q;
	loop(i, n)
		loop(j, m) { 
		cin >> board[i][j];
		if (board[i][j] == 1) q.push({ i, j });
	}
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		loop(i, 4) {
			int nx = x + dx[i]; int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (board[nx][ny] == -1) continue;
				if (board[nx][ny] == 0) {
					board[nx][ny] = board[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	int res = -1;
	loop(i, n)
		loop(j, m) {
		if (board[i][j] == 0) {
			cout << -1 << endl;
			return 0;
		}
		res = max(res, board[i][j]);
	}
	cout << res -1<< endl;
	return 0;
}