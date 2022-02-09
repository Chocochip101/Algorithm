#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 101
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;
int N, L; 
int board[MAX][MAX];
bool visited[MAX][MAX];

int cntCol() {
    int ans = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; ++i) {
        bool canGo = true;
        for (int j = 0; j < N - 1; ++j) {
            if (board[i][j] == board[i][j + 1]) continue;
            if (abs(board[i][j] - board[i][j + 1]) > 1) {
                canGo = false;
                break;
            }
            else if (board[i][j] < board[i][j + 1]) {
                if (j - L + 1 < 0) { canGo = false; break; }
                for(int k = j - L + 1; k <=j; ++k)
                    if (visited[i][k] || board[i][k] != board[i][j]) {
                        canGo = false; break;
                    }
                for (int k = j - L + 1; k <= j; ++k)
                    visited[i][k] = true;

            }
            else if (board[i][j] > board[i][j + 1]) {
                if (j + L >= N) { canGo = false; break; }

                for(int k = j + 1; k <= j + L; ++k)
                    if (visited[i][k] || board[i][k] != board[i][j + 1]) {
                        canGo = false; break;
                    }
                for (int k = j + 1; k <= j + L; ++k)
                    visited[i][k] = true;
            }

        }
        if (canGo) { ans++; }
    }
    return ans;
}
int cntRow() {
    int ans = 0;
    memset(visited, false, sizeof(visited));
    for (int j = 0; j < N; ++j) {
        bool canGo = true;
        for (int i = 0; i < N - 1; ++i) {
            if (board[i][j] == board[i + 1][j]) continue;
            if (abs(board[i][j] - board[i + 1][j]) > 1) { canGo = false; break; }
            else if (board[i][j] < board[i + 1][j]) {
                if (i - L + 1 < 0) { canGo = false; break; }

                for (int k = i - L + 1; k <= i; ++k) 
                    if (visited[k][j] || board[k][j] != board[i][j]) {
                        canGo = false; break;
                    }
                for (int k = i - L + 1; k <= i; ++k)
                    visited[k][j] = true;
            }
            else if (board[i][j] > board[i + 1][j]) {
                if (i + L >= N) { canGo = false; break; }
                for (int k = i + 1; k <= i + L; ++k)
                    if (visited[k][j] || board[k][j] != board[i + 1][j]) {
                        canGo = false; break;
                    }
                for (int k = i + 1; k <= i + L; ++k)
                    visited[k][j] = true;

            }

       }
        if (canGo) {ans++; }
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> L;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    cout << cntCol() + cntRow() << endl;
    return 0;
}