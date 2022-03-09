#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 2001
using namespace std;
typedef pair<int, int> p;

int N, K;
int num[MAX];
int arr[MAX];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> num[i];
    
    for(int i = 1; i < N; ++i)
        arr[i - 1] = num[i] - num[i - 1];
    
    sort(arr, arr + N - 1);

    int ans = 0;
    for(int i = 0; i < N - K; ++i)
        ans += arr[i];
    cout << ans;
	return 0;
}