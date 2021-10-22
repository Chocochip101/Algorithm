#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 13
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;
struct CHESS {
    int x;
    int y;
    int dir;
    bool IsButtom;
};

p Dir[5] = { {0, 0}, {0 ,1}, {0, -1}, {-1, 0}, {1, 0} };
vector<int> MapState[MAX][MAX];
CHESS chess[11];
int board[MAX][MAX];
int N, K;

//Is x, y, valid?
bool valid(int nx, int ny) {
    return 0 <= nx && nx < N && 0 <= ny && ny < N; 
}
//Reverse Chess
void ReverseChess(int x, int y) {
    reverse(MapState[x][y].begin(), MapState[x][y].end());
    chess[MapState[x][y][0]].IsButtom = true;
    for (int i = 1; i < MapState[x][y].size(); ++i)
        chess[MapState[x][y][i]].IsButtom = false;
}
//Reverse Dir
int ReverseDir(int d) {
    if (d == 1) return 2;
    else if (d == 2) return 1;
    else if (d == 3) return 4;
    else if (d == 4) return 3;
}
//Move chess
void Move(int x, int y, int nx, int ny, int color) {
    if (color == 0) {
        //가려는 곳에 말이 있는 경우
        if (MapState[nx][ny].size() != 0) chess[MapState[x][y][0]].IsButtom = false;
        // Move
        for (int i = 0; i < MapState[x][y].size(); ++i) {
            MapState[nx][ny].push_back(MapState[x][y][i]);
            chess[MapState[x][y][i]].x = nx;
            chess[MapState[x][y][i]].y = ny;
        }
        MapState[x][y].clear();
    }
    else if (color == 1) {
        ReverseChess(x, y);
        for (int i = 0; i < MapState[x][y].size(); ++i) {
            MapState[nx][ny].push_back(MapState[x][y][i]);
            chess[MapState[x][y][i]].x = nx;
            chess[MapState[x][y][i]].y = ny;
        }
        MapState[x][y].clear();
        for (int i = 1; i < MapState[nx][ny].size(); ++i)
            chess[MapState[nx][ny][i]].IsButtom = false;
    }
    else if (color == 2) {
        int nd = ReverseDir(chess[MapState[x][y][0]].dir);
        chess[MapState[x][y][0]].dir = nd;
        nx = x + Dir[nd].first;
        ny = y + Dir[nd].second;
        if (valid(nx, ny))
            if (board[nx][ny] != 2)
                Move(x, y, nx, ny, board[nx][ny]);
    }
}
bool Check() {
    for (int i = 0; i < K; ++i) 
        if (MapState[chess[i].x][chess[i].y].size() >= 4) return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    for (int i = 0; i < K; ++i) {
        int x, y, d; cin >> x >> y >> d; 
        x--; y--;
        chess[i] = { x, y, d, true };
        MapState[x][y].push_back(i);
    }

    bool canMake = false;
    int cnt = 0;
    while (1) {
        if (Check()) {
            canMake = true;
            break;
        }
        if (cnt > 1000) break;

        for (int i = 0; i < K; ++i) {
            if (!chess[i].IsButtom) continue;
            int x = chess[i].x; int y = chess[i].y;
            int dir = chess[i].dir;

            int nx = x + Dir[dir].first;
            int ny = y + Dir[dir].second;
            if (valid(nx, ny)) Move(x, y, nx, ny, board[nx][ny]);
            else Move(x, y, nx, ny, 2);
        }
        cnt++;
    }

    if (canMake) cout << cnt << endl;
    else cout << -1 << endl;
    return 0;
}