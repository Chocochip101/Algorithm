#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 51
#define MOD 10007
using namespace std;
typedef pair<int, int> p;
int N;
string board[MAX][5];
int sim(int x, int y){
    int res = 0;
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 7; ++j)
            if(board[x][i][j] == board[y][i][j])
                res++;
    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; ++i)
        for(int j = 0; j < 5; ++j)
            cin >> board[i][j];

    int cnt = -1;
    int f, s; 
    for(int i = 1; i <= N; ++i)
        for(int j = i + 1; j <= N; ++j)
            if(cnt < sim(i, j)){
                cnt = sim(i, j);
                f = i; s = j;
            }
    cout << f << " " << s;
	return 0;
}