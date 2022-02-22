#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 5000
#define int ll
using namespace std;

int M;
int cntFive(int n){
    int cnt = 0;
    while(n >= 5){
        cnt++;
        n /= 5;
    }
    return cnt;
}

// n 이하의 5의 개수
int fives(int n){
    int cnt = 0;
    for(int i = 5; i <= n; i += 5)
        cnt += cntFive(i);
    return cnt;
}


int solve(int m){
    int s = 0, e = MAX;
    while(s < e){
        int mid = (s + e) / 2;
        int n = fives(mid);
        if(n == m) return mid;
        else if(n > m) e = mid - 1;
        else s = mid + 1;
    }
    return s;
}
signed main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
    cin >> M;
    int ans = solve(M);
    ans -= ans % 5;
    if(fives(ans) == M)
        cout << ans;
    else 
        cout << -1;
	return 0;
}