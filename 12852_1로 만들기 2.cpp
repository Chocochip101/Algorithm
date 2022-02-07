#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1000001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

int cache[MAX];
int trace[MAX];
int solve(int x) {
    if (x == 0) return INF;
    if (x == 1)  return 0; 

    int& ret = cache[x];
    if (ret != -1) return ret;

    ret = INF;
    if (x % 3 == 0 && (ret > solve(x / 3) + 1)) {
        ret =  solve(x / 3) + 1;
        trace[x] = x / 3;
    }
    if (x % 2 == 0 && (ret > solve(x / 2) + 1)) {
        ret = solve(x / 2) + 1;
        trace[x] = x / 2;
    }
    if (ret > (solve(x - 1) + 1)) {
        ret = solve(x - 1) + 1;
        trace[x] = x - 1;
    }
    return ret;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

     int x; cin >> x;
     memset(cache, -1, sizeof(cache));

     
         cout << solve(x) << endl;

         while (x != 0) {
             cout << x << " ";
             x = trace[x];
         }
     
    return 0;
}