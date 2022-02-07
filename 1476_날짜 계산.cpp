#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1001
#define INF 987654321
#define int ll
using namespace std;
typedef pair<int, int> p;

int E, S, M;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> E >> S >> M;
   
    int Y = 1;
    while (1) {
        if ((Y - E) % 15 == 0 && (Y - S) % 28 == 0 && (Y - M) % 19 == 0) {
            cout << Y;
            break;
        }
        Y++;
    }
    return 0;
}