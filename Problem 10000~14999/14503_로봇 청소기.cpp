#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 1001
using namespace std;
typedef pair<int, int> p;
p Dir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int n, m, direction;
int board[51][51];
bool visited[51][51];

void turnLeft() {
	direction--;
	if (direction == -1)
		direction = 3;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	p robot;

	cin >> n >> m >> robot.first >> robot.second >> direction;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	memset(visited, false, sizeof(visited));

	visited[robot.first][robot.second] = true;
	int ans = 1;
	int turnTime = 0;

	while (true) {
		turnLeft();

		int nx = robot.first + Dir[direction].first;
		int ny = robot.second + Dir[direction].second;
		if (!visited[nx][ny] && board[nx][ny] == 0) {
			visited[nx][ny] = true;
			ans++;
			robot.first = nx;
			robot.second = ny;
			turnTime = 0;
			continue;
		}
		else turnTime++;

		if (turnTime == 4) {
			nx = robot.first - Dir[direction].first;
			ny = robot.second - Dir[direction].second;
			if (board[nx][ny] == 0) {
				robot.first = nx;
				robot.second = ny;
			}
			else
				break;
			turnTime = 0;
		}

	}
	cout << ans << endl;
	return 0;
}