#include<bits/stdc++.h>
#define endl "\n"
#define MAX 201
#define INF 987654321
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

p Dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, K, S;
int board[MAX][MAX];
bool valid(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}
void bfs(){
    int cnt = 0;
    queue<p> q;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j){
            if(board[i][j] != 0)
                q.push({i, j});
    }

    while(!q.empty()){
        if(cnt == S) return;
        cnt++;
        int q_size = q.size();
        vector<pair<int, p>> vc;
        while(q_size--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vc.push_back({board[x][y], {x, y}});
        }
        sort(vc.begin(), vc.end());
        for(auto coord: vc){
            int x = coord.second.first;
            int y = coord.second.second;
            int num = coord.first;

            for(int i = 0; i < 4; ++i){
                int nx = x + Dir[i].first;
                int ny = y + Dir[i].second;
                if(valid(nx, ny) && board[nx][ny] == 0){
                    board[nx][ny] = num;
                    q.push({nx, ny});
                }
            }
        }
    }
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int X, Y;
    cin >> N >> K;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            cin >> board[i][j];
    cin >> S >> X >> Y;
    bfs();
    cout << board[X][Y];
	return 0;
}