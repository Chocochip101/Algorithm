#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 100001
#define int ll
using namespace std;
typedef pair<int, int> p;

int C, N;
double solvePos(int x, int y){
    double VAL = x * pow(C, 2) + sqrt(pow(C, 4) * pow(x, 2) - 20 * pow(x, 2) * (y * pow(C, 2) + 5 * pow(x, 2)));
    return VAL / (10 * pow(x, 2));
}

double solveMin(int x, int y){
    double VAL = x * pow(C, 2) - sqrt(pow(C, 4) * pow(x, 2) - 20 * pow(x, 2) * (y * pow(C, 2) + 5 * pow(x, 2)));
    return VAL / (10 * pow(x, 2));
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
    int a, b;
    while(tc--){
        double left = -INFINITY, right = INFINITY;
        cin >> C >> N;
        for(int i = 0; i < N; ++i){
            cin >> a >> b;
            left = max(left, solveMin(a, b));
            right = min(right, solvePos(a, b));
        }
        cout << fixed;
        cout.precision(3);
        cout << (left + right) / 2 << endl;
    }
	return 0;
}