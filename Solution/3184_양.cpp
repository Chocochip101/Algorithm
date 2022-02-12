#include<bits/stdc++.h>
#define endl "\n"
#define MAX 251
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

p Dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int R, C;
string board[MAX];
bool visited[MAX][MAX];
int SheepNum, WolfNum;
bool valid(int x, int y){return 0 <= x && x < R && 0 <= y && y < C;}
void dfs(int x, int y){
    visited[x][y] = true;

    if(board[x][y] == 'o')
        SheepNum++;
    else if(board[x][y] == 'v')
        WolfNum++;
    
    for(int i = 0; i < 4; ++i){
        int nx = x + Dir[i].first;
        int ny = y + Dir[i].second;

        if(valid(nx, ny) && board[nx][ny] != '#' && !visited[nx][ny])
            dfs(nx, ny);
    }
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(visited, false, sizeof(visited));
    int resSheep = 0, resWolf = 0;
	cin >> R >> C;
    for(int i = 0;i < R; ++i){
        cin >> board[i];
    }

    for(int i = 0; i < R; ++i)
        for(int j = 0; j < C; ++j){
            SheepNum = 0; WolfNum = 0;
            if(board[i][j] != '#' && !visited[i][j])
                dfs(i, j);
            if(SheepNum > WolfNum)
                resSheep += SheepNum;
            else
                resWolf += WolfNum;
        }

    cout << resSheep << " " << resWolf;

	return 0;
}