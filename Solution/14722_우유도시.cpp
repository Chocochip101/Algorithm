#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1001
#define INF 987654321
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

p Dir[2] = {{0, 1}, {1, 0}};

int N; 
int board[MAX][MAX];
int cache[MAX][MAX][4];
bool valid(int x, int y) {return 0 <= x && x < N && 0 <= y && y < N;}
int nextMilk(int a){
    if(a == 2) return 0;
    return a + 1;
}

int solve(int x, int y, int now){
    if(!valid(x, y)) return 0;

    int&ret = cache[x][y][now + 1];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < 2; ++i){
        int nx = x + Dir[i].first;
        int ny = y + Dir[i].second;

        if(valid(nx, ny)){
            // Pass
            ret = max(ret, solve(nx, ny, now));
            // 현재 우유를 마시거나
            if(board[nx][ny] == nextMilk(now))
                ret = max(ret, solve(nx, ny, nextMilk(now)) + 1);
            
        }
    }

    return ret;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin >> board[i][j];

    if(board[0][0] == 0)
        cout << solve(0 ,0, 0) + 1 << endl;
    else 
        cout << solve(0, 0, -1) << endl;
	return 0;
}