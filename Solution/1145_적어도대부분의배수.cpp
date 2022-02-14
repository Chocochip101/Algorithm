#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000000000
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;

int arr[5];

// a < b
int LCM(int a, int b){
    if(b % a == 0) return a;
    return LCM(b % a, a);
}
int solve(int a, int b){
    return a * b / LCM(a, b);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    for(int i = 0; i < 5; ++i)
        cin >> arr[i];
    sort(arr, arr + 5);
    int ans = INF;
    for(int i = 0; i < 5; ++i)
        for(int j = i + 1; j < 5; ++j)
            for(int k = j + 1; k < 5; ++k)
                ans = min(ans, solve(solve(arr[i], arr[j]), arr[k]));
    cout << ans << endl;
	return 0;
}