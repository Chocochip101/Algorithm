#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 21
#define MOD 1000000000
#define PI 3.1415926254
using namespace std;
typedef pair<int, int> p;

int n, shark_size = 2, ans = 0;
int cnt = 0;
int visited[MAX][MAX];
int board[MAX][MAX];
vector<pair<int, pair<int, int>>> ord;	//거리 정보, 좌표
p shark_coord;

p Dir[4] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };


bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first)
			return a.second.second < b.second.second;
		return a.second.first < b.second.first;
	}
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 0; i <n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				board[i][j] = 0;
				shark_coord.first = i;
				shark_coord.second = j;
			}
		}
	while (1) {

		memset(visited, -1, sizeof(visited));
		bool found = false;

		queue<p> q;
		q.push({shark_coord.first, shark_coord.second});
		visited[shark_coord.first][shark_coord.second] = 0;

		while (!q.empty()) {

			int x = q.front().first; int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int nx = x + Dir[i].first; int ny = y + Dir[i].second;
				if (0 <= nx && nx < n && 0 <= ny && ny < n && visited[nx][ny] == -1) {

					//더 큰 상어
					if (board[nx][ny] > shark_size) continue;

					//상어 발견
					if (board[nx][ny]  < shark_size && board[nx][ny] != 0) {
						found = true;
						visited[nx][ny] = visited[x][y] + 1;
						ord.push_back({ visited[nx][ny], {nx, ny} });
						continue;
					}

					//그냥 지나갈 경우
					visited[nx][ny] = visited[x][y] + 1;
					q.push({ nx, ny });

				}
			}
		}
		if (!found) break;
		else {
			sort(ord.begin(), ord.end(), cmp);
			ans += ord[0].first;
			shark_coord = ord[0].second;
			cnt++;
			if (cnt == shark_size) {
				shark_size++; cnt = 0;
			}
			board[shark_coord.first][shark_coord.second] = 0;
			ord.clear();
		}
	}
	cout << ans << endl;
	return 0;
}