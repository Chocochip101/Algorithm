#include <bits/stdc++.h>
#define endl "\n"
#define MAX  401
#define int long long
using namespace std;
typedef pair<int, int> p;
int N, K;
int board[MAX][MAX];
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int i = 0; i < K; ++i){
        int a, b;cin >> a >> b;
        board[a][b] = -1;
        board[b][a] = 1;
    }

    for(int t = 1; t <= N; ++t)
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                if(board[i][t] == board[t][j] && board[i][t] != 0)
                    board[i][j] = board[i][t];

    int tc; cin >> tc;
    while(tc--){
        int a, b; cin >> a >> b;
        cout << board[a][b] << endl;
    }
	return 0;
}