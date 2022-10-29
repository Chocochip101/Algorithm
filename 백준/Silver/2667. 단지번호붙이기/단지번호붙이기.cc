#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 26
using namespace std;
int n;
int cnt = 0;
vector<int> danji;
vector<string> board;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
	cnt++;
	board[x][y] = '0';
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i]; int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (board[nx][ny] == '1')
				dfs(nx, ny);
		}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		board.push_back(s);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (board[i][j] == '1') {
				cnt = 0;
				dfs(i, j);
				danji.push_back(cnt);
	}

	cout << danji.size() << endl;
	sort(danji.begin(), danji.end());
	for (int i = 0; i < danji.size(); ++i)
		cout << danji[i] << endl;

	return 0;
}