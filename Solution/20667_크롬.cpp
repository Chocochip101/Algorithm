#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 101
using namespace std;
struct info{
    int cpu, memory, priority;
};
int N, M, K;
info arr[MAX];
// idx, cpu, priority
int cache[MAX][MAX * 10][MAX * 5];

int solve(int idx, int c, int p){
    if(idx == N){ 
        if(c >= M)
            return 0;
        else 
            return -INF;
    }

    int&ret = cache[idx][c][p];
    if(ret != -1)return ret;

    ret = -INF;
    // 탭을 닫지 않음
    ret = max(ret, solve(idx + 1, c, p));

    // 탭 닫기
    if(p >= arr[idx].priority){
        int temp = min(arr[idx].cpu + c, MAX * 10 - 1);
        ret = max(ret, solve(idx + 1, temp, p - arr[idx].priority) + arr[idx].memory);
    }

    return ret;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> N >> M >> K;

    for(int i = 0; i < N; ++i)
        cin >> arr[i].cpu >> arr[i].memory >> arr[i].priority;

    int ans = -1;
    for(int i = 0; i < MAX * 5; ++i){
        int temp = solve(0, 0, i);
        if(temp < K || temp == -INF)
            continue;
        ans = i;
        break;
    }
    cout << ans;
	return 0;
}