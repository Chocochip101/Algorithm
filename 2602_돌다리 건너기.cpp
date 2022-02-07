#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000001
#define INF 987654321
#define ll long long
using namespace std;
typedef pair<int, int> p;

string magic;
string board[2];
int board_size;
int magic_size;
int cache[21][101][2];
int solve(int m_idx, int b_idx, int dir) {
	if (m_idx == magic_size - 1) return 1;

	int& ret = cache[m_idx][b_idx][dir];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = b_idx + 1; i < board_size; ++i) {

		if (dir == 0 && board[1][i] == magic[m_idx + 1])
			ret += solve(m_idx + 1, i, 1);

		else if (dir == 1 && board[0][i] == magic[m_idx + 1])
			ret += solve(m_idx + 1, i, 0);
	}
	return ret;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> magic;
	magic_size = magic.size();
	for (int i = 0; i < 2; ++i)
		cin >> board[i];
	board_size = board[0].size();
	
	int ans = 0;
	for (int i = 0; i < board_size; ++i)
		for (int dir = 0; dir < 2; ++dir)
			if (magic[0] == board[dir][i])
				ans += solve(0, i, dir);
	cout << ans;

	return 0;
}