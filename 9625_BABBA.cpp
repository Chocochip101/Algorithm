#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 46
#define INF 987654321

using namespace std;
typedef pair<int, int> p;
int k;
int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    A[1] = 0; B[1] = 1;
    for (int i = 2; i <= k; ++i) {
        A[i] = B[i - 1];
        B[i] = A[i - 1] + B[i - 1];
    }
    cout << A[k] << " " << B[k];
    return 0;
}