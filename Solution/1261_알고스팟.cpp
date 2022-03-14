#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 101
using namespace std;
typedef pair<int, int> p;
p Dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N, M;
string board[MAX];
int dist[MAX][MAX];
bool valid(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}
void solve(p src){
    priority_queue<pair<int, p>> pq;
    pq.push({0, src});
    dist[src.first][src.second] = 0;

    while(!pq.empty()){
        int c = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(c > dist[x][y]) continue;
        for(int i = 0; i < 4;++i){
            int nx = x + Dir[i].first;
            int ny = y + Dir[i].second;
            if(valid(nx, ny)){
                if(dist[nx][ny] == -1 || (dist[nx][ny] > dist[x][y] + (board[x][y] - '0')) ){
                    dist[nx][ny] = dist[x][y] + (board[x][y] - '0');
                    pq.push({ - dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
}

int main() {
    cin >> M >> N;
    memset(dist, -1, sizeof(dist));
    for(int i = 0; i < N; ++i)
        cin >> board[i];
    solve({0, 0});
    cout << dist[N -1][M - 1];
	return 0;
}