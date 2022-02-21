#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 2001
#define PRIMEMAX 1000001
#define int ll
using namespace std;
typedef pair<int, int> p;
// 상, 우, 하, 좌
p Dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N, M;
int board[MAX][MAX];
bool visited[MAX][MAX][4];

bool valid(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}
int turnDir(int bb, int d){
    if(bb == 1){
        if(d == 1 || d == 3) return -1;
        else  return d;
    
    }else if(bb == 2){
        
        if(d == 0 || d == 2) return -1;
        else return d;

    }else if(bb == 3){
        if(d == 0)
            return 1;
        else if(d == 1)
            return 0;
        else if(d == 2)
            return 3;
        else if(d == 3)
            return 2;  
    }else if(bb == 4){
        if(d == 0)
            return 3;
        else if(d == 1)
            return 2;
        else if(d == 2)
            return 1;
        else if(d == 3)
            return 0;
    }
    return d;
}
void dfs(int x, int y, int d){

    visited[x][y][d] = true;
    d = turnDir(board[x][y], d);
    if(d == -1) return;

    int nx = x + Dir[d].first;
    int ny = y + Dir[d].second;

    if(valid(nx, ny) && !visited[nx][ny][d])
        dfs(nx, ny, d);
    return;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    memset(visited, false, sizeof(visited));
    vector<p> air;
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j){
            cin >> board[i][j];
            if(board[i][j] == 9){
                air.push_back({i, j});
                board[i][j] = 0;
            }
    }

    for(p coord: air)
        for(int i = 0; i < 4; ++i)
            dfs(coord.first, coord.second, i);

    int ans = 0;
    for(int i = 0; i <N; ++i){
        for(int j = 0; j < M; ++j){
            bool flag = false;
            for(int k = 0; k < 4; ++k)
                if(visited[i][j][k])
                    flag = true;
            if(flag)
                ans++;
        }
    }
    cout << ans << endl;
	return 0;
}