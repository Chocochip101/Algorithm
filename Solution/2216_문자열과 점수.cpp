#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
using namespace std;

int cache[3001][3001];
int a, b, c;
string X, Y;
int Xlen, Ylen;

int solve(int idx1, int idx2) {
    int& ret = cache[idx1][idx2];
    if (ret != -INF) return ret;
    ret = 0;
    if (idx1 == Xlen && idx2 == Ylen) return ret;

    int temp = -INF;
    if (idx1 < Xlen && idx2 < Ylen) {
        if (X[idx1] == Y[idx2])
            temp = max(temp, solve(idx1 + 1, idx2 + 1) + a);
        else
            temp = max(temp, solve(idx1 + 1, idx2 + 1) + c);
    }
    if (idx1 < Xlen)
        temp = max(temp, solve(idx1 + 1, idx2) + b);
    if (idx2 < Ylen)
        temp = max(temp, solve(idx1, idx2 + 1) + b);
    return ret += temp;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c >> X >> Y;

    Xlen = X.size();
    Ylen = Y.size();
    loop(i, Xlen + 1) loop(j, Ylen + 1) cache[i][j] = -INF;

    cout << solve(0, 0) << endl;
    return 0;
}
