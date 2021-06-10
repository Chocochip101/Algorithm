#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX 100001
using namespace std;
int n;
int cache[MAX];

bool isSquare(int num) {
    return (num == pow((int)sqrt(num), 2)) ? true : false;
}

int solve(int num) {
    int& ret = cache[num];

    if (isSquare(num)) return 1;
    if (ret != -1) return ret;

    ret = INF;
    for (int i = 1; i <= (int)sqrt(num); ++i) {
        ret = min(ret, 1 + solve(num - i * i));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(0); cout.tie(0);

    cin >> n;
    memset(cache, -1, sizeof(cache));

    cout << solve(n) << endl;
    return 0;
}