#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000001
#define INF 987654321
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;


int solve(int k){
    if(k == 1)return 0;
    int i;
	for(i=1; i + i < k; i+=i);
	return !solve(k - i);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int K; cin >> K;
    cout << solve(K);
	return 0;
}