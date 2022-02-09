#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 11
using namespace std;
typedef pair<int, int> p;
p Dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0 , -1}};
int N, M, K;
int board[MAX][MAX];
bool visited[MAX][MAX];
int ans = -INF;
bool valid(int x, int y){
	for (int i = 0;i < 4;++i) {
		int nx = x + Dir[i].first;
		int ny = y + Dir[i].second;
		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (visited[nx][ny] == true) {
				return false;
			}
		}
	}
	return true;
}
void solve(int cnt, int parSum){
	if(cnt == K){ 
		ans = max(ans, parSum);
		return;
	}


	for(int i = 0 ; i < N; ++i)
		for(int j = 0; j < M; ++j)
		{
			if(!visited[i][j] && valid(i, j)){
				visited[i][j] = true;
				solve(cnt + 1, parSum + board[i][j]);
				visited[i][j] = false;
			}
		}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(visited, false, sizeof(visited));

	cin >> N >> M >> K;
	for(int i = 0; i <N; ++i)
		for(int j = 0; j <M; ++j)
			cin >> board[i][j];


	solve(0, 0);

	cout << ans << endl;
	return 0;
}