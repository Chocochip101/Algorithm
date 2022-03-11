#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 5001
#define MOD 1000000007
using namespace std;

int N, M;
int board[MAX][MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> N >> M;

    for(int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        board[a][b] = 1;
        board[b][a] = -1;
    }
    for(int t = 1; t <= N; ++t)
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                if(board[i][t] == board[t][j] && board[i][t] != 0)
                    board[i][j] = board[i][t];
    for(int i = 1; i <= N; ++i){
        int cnt = 0;
        for(int j = 1; j <= N; ++j)
            if(board[i][j] != 0) cnt++;
        cout << N - cnt - 1 << endl;
    }
	return 0;
}