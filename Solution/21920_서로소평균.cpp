#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 500001
#define PRIMEMAX 1000001
#define int ll
using namespace std;

int N;
int arr[MAX];
int X;
// 6 8
int solve(int a, int b){
    if(a > b) swap(a, b);
    if(b % a == 0) return a;
    return solve(b % a, a);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    cin >> X;

    double ans = 0;
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        if(solve(X, arr[i]) == 1){
            cnt++;
            ans += arr[i];
        }
    }
    printf("%lf",ans / cnt);
	return 0;
}