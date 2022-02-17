#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int ll
#define MAX  52
#define MOD 998244353
using namespace std;
typedef pair<int, int> p;
p Dir[9] = {{0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

int N, M;
// 바구니에 들은 물의 양
int A[MAX][MAX];
// 이전에 생성된 구름: 1, 다음에 생성된 구름: 2
int cloud[MAX][MAX] = {0, };
bool valid(int x, int y){
    return 1 <= x && x <= N && 1 <= y && y <= N;
}
int chgRange(int x){
    if(x == 0) return N;
    else if(x == N + 1) return 1; 
    else return x;
}
void moveCloud(int d, int s){
    vector<p> vc;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j){
            if(cloud[i][j] == 1){
                int nx = i;
                int ny = j;
                
                for(int k = 0; k < s;++k){
                    nx += Dir[d].first;
                    ny += Dir[d].second;
                    nx = chgRange(nx);
                    ny = chgRange(ny);
                }
                vc.push_back({nx, ny});
                cloud[i][j] = 0;
            }
        }
    for(p a: vc)
        cloud[a.first][a.second] = 1;
}
void rain(){
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            if(cloud[i][j] == 1)
                A[i][j]++;
}
void waterCopyBug(){
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j){
            if(cloud[i][j] == 1){
                int temp = 0;
                for(int d = 1; d <= 4; ++d){
                    int nx = i + Dir[d * 2].first;
                    int ny = j + Dir[d * 2].second;
                    if(valid(nx, ny) && A[nx][ny] > 0)
                        temp++;
                }
                A[i][j] += temp;
        }
    }
}
void makeCloud(){
    for(int i = 1; i <=N; ++i)
        for(int j = 1; j <= N; ++j){
             if(A[i][j] >= 2 && cloud[i][j] != 1){
                A[i][j] -= 2;
                cloud[i][j] = 2;
            } 
        }
    // 기존 구름 제거
    for(int i = 1; i <=N; ++i)
        for(int j = 1; j <= N; ++j)
            if(cloud[i][j] == 1)
                cloud[i][j] = 0;
            else if(cloud[i][j] == 2)
                cloud[i][j] = 1;
}
int result(){
    int res = 0;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            res += A[i][j];
    return res;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    cin >> N >>M;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)  
            cin >> A[i][j];

    cloud[N][1] = 1;
    cloud[N][2] = 1;
    cloud[N - 1][1] = 1;
    cloud[N - 1][2] = 1;

    for(int i = 0; i < M; ++i){
        int d, s; cin >> d >> s;
        moveCloud(d, s);
        rain();
        waterCopyBug();
        makeCloud();
    }

    cout <<result() << endl;
	return 0;
}