#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 301
#define MOD 10007
using namespace std;
typedef pair<int, int> p;

int N, M;
int board[MAX][MAX];
int solve(int a, int b, int c, int d){
    int res = 0;
    for(int i = a; i <= c; ++i)
        for(int j = b; j <= d; ++j)
            res += board[i][j];

    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < M; ++j)
            cin >> board[i][j];
    int tc; cin >> tc;
    while(tc--){
        int a, b, c, d; cin >> a >> b>> c>>d;
        a--; b--; c--; d--;
        cout << solve(a, b, c, d)<< endl;
    }

        
  	return 0;
}