#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define MAX 501
using namespace std;
typedef pair<int, int> p;

p Dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N, M, A, B, K;
int dist[MAX][MAX];
queue<p> q;
p src, dest;
bool valid(int x, int y){
    int nx = x + A;
    int ny = y + B;
    return 1 <= x && x <= N && 1 <= y && y <= M && 1 <= nx && nx <= N && 1 <= ny && ny <= M;
}
bool canMove(int nx, int ny){
    for(int i = nx; i < nx + A; ++i)
        for(int j = ny; j < ny + B; ++j)
            if(dist[i][j] == -2)
                return false;
    return true; 
}
int bfs(){
    q.push(src);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == dest.first && y == dest.second) return dist[x][y];
        for(int i = 0; i < 4; ++i){
            int nx = x + Dir[i].first;
            int ny = y + Dir[i].second;
            if(valid(nx, ny) && dist[nx][ny] == -1 && canMove(nx, ny)){
                q.push({nx,ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof(dist));

    cin >> N >> M >> A >> B >> K;
    for(int i = 0; i < K; ++i){
        int a, b; cin >> a>> b;
        dist[a][b] = -2;
    }

    cin >> src.first >> src.second;
    dist[src.first][src.second] = 0;
    cin >> dest.first >> dest.second;

    cout << bfs() << endl;

	return 0;
}