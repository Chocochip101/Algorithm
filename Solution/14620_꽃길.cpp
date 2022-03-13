#include<bits/stdc++.h>
#define endl "\n"
#define MAX 12
#define INF 987654321
#define MOD 1001
using namespace std;
typedef pair<int, int> p;
p Dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N;
int board[MAX][MAX];
bool visited[MAX][MAX];
int ans = INF;
bool valid(int x, int y){
    return 0 <= x && x < N && 0 <= y &&  y < N;
}
bool check(int x, int y){
    if(visited[x][y]) return false;
    for(int i = 0; i < 4; ++i){
        int nx = x + Dir[i].first;
        int ny = y + Dir[i].second;
        if(!valid(nx, ny) || visited[nx][ny]) return false;
    }
    return true;
}

void solve(int cnt, int parSum, int src){
    if(cnt == 3){
        ans = min(ans, parSum);
        return;
    }
    for(int i = src; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(!check(i, j))
                continue;
            
            int c = board[i][j];
            visited[i][j] = true;
            for(int d = 0; d < 4; ++d){
                int nx = i + Dir[d].first;
                int ny = j + Dir[d].second;
                c += board[nx][ny];
                visited[nx][ny] = true;
            }

            solve(cnt + 1, parSum + c, i);
            visited[i][j] = false;
            for(int d = 0; d < 4; ++d){
                int nx = i + Dir[d].first;
                int ny = j + Dir[d].second;
                visited[nx][ny] = false;
            }

        }
    }


}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(visited, false, sizeof(visited));
    cin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> board[i][j];
    solve(0, 0, 1);
    cout << ans;
	return 0;
}