#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 27
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

int N, M;
bool board[MAX][MAX];

int solve(int x, int y){
    int res = 0;
    if(y > M){
       x += 1;
       y = 1;
    }
    if(x > N) return 0;

    if(!board[x - 1][y] || !board[x][y - 1] || !board[x - 1][y - 1]){
        board[x][y] = true;
        res += (1 + solve(x, y + 1));
        board[x][y] = false;
    }
    res += solve(x, y + 1);
    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(board, false, sizeof(board));
    cin >> N >> M;
    cout << solve(1, 1) + 1 <<endl;
  	return 0;
}