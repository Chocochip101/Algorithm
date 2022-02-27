#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 126
#define MOD 1000000000
#define int ll
using namespace std;
typedef pair<int, int> p;
int N;
void solve(int n){
    if(n == 0){
        cout << "-";
        return;
    }
    solve(n - 1);
    for(int i = 0; i < (int)pow(3, n - 1); ++i)
        cout << " ";
    solve(n - 1);

}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    while(cin >> N){
        solve(N);
        cout << endl;
    }
	return 0;
}
