#include<bits/stdc++.h>
#define endl '\n'
#define MAX 202
#define INF 987654321
#define int long long 
using namespace std;

int N, M, K;
int board[MAX][MAX];
int arr[MAX];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j){
            if(i == j) board[i][j] = 0;
            else board[i][j] = INF;
    }

    for(int i = 0; i < M; ++i){
        int a, b, c;  cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
    }

    for(int t = 1; t <= N; ++t)
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                board[i][j] = min(board[i][j], board[i][t] + board[t][j]);

    cin >> K;
    for(int i = 0; i < K; ++i)
        cin >> arr[i];

    vector<int> ans;
    int minDist = INF;
    for(int now = 1; now <= N; ++now){
        int temp = -1;
        bool flag = true;
        for(int i = 0; i < K; ++i){
            if(board[arr[i]][now] + board[now][arr[i]] >= INF){
                flag = false;
                break;
            }
            temp = max(temp, board[arr[i]][now] + board[now][arr[i]]);
        }

        if(flag){
            if(temp < minDist){
                minDist = temp;
                ans.clear();
                ans.push_back(now);
            }else if(temp == minDist){
                ans.push_back(now);
            }
        }
    }
    for(int a: ans)
        cout << a << " ";
    return 0;
}