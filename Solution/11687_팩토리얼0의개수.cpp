#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 100000000
using namespace std;

int M;
int cntFive(int n){
    int cnt = 1;
    while(n % 5 == 0){
        cnt++;
        n /= 5;
    }
    return cnt;
}

int solve(int m){        
    int cnt = 0;
    for(int i = 1; i <= MAX; ++i){
        cnt += cntFive(i);
        if(cnt == m)
            return i * 5;
        else if(cnt > m)
            return -1;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
    cin >> M;
    cout << solve(M);
	return 0;
}