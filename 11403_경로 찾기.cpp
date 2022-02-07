#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 101
using namespace std;
int n;
bool board[MAX][MAX];
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(board, false, sizeof(board));
    cin >> n;
    loop(i, n)
        loop(j, n) {
        int temp; cin >> temp;
        if (temp == 1)
            board[i][j] = true;
    }

    loop(k, n)
        loop(i, n)
        loop(j, n)
        if (board[i][k] && board[k][j])
            board[i][j] = true;
    loop(i, n) {
        loop(j, n)
            cout << board[i][j] << " ";
        cout << endl;
    }
    return 0;
}
