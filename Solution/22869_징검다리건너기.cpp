#include<bits/stdc++.h>
#define endl "\n"
#define MAX 5002
#define INF 987654321
#define MOD 1001
#define ll long long
using namespace std;
typedef pair<int, int> p;

int N, K;
int A[MAX];
int cache[MAX];
int dfs(int now){
    if(now == N - 1) return 1;

    int &ret = cache[now];
    if(ret != -1) return ret;

    for(int i = now + 1; i <N; ++i)
        if(K >= (i - now) * (1 + abs(A[i] - A[now])) )
            ret = dfs(i);
    return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    memset(cache, -1, sizeof(cache));
	cin >> N >> K;
    for(int i = 0; i <N; ++i)
        cin >>A[i];
    dfs(0);
    for(int i = 0; i <N; ++i)
        if(cache[i] == 1){
            cout << "YES";
            return 0;
        }

    cout << "NO";
	return 0;
}