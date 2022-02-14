#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 366
using namespace std;
typedef pair<int, int> p;

int N;
int y[MAX];
vector<p> vc;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> N;
    for(int i = 0; i < N; ++i){
        int a, b; cin >> a>> b;
        vc.push_back({a, b});
        for(int j = a; j <= b; ++j)
            y[j]++;
    }

    sort(vc.begin(), vc.end());

    int ans = 0;
    int w = 0, h = 0;
    for(int i = 1; i < MAX; ++i){
        if(y[i]){
            h = max(h, y[i]);
            w++;
        }
        if(y[i] == 0 || i == 365){
            ans += w * h;
            w = 0; h = 0;
        }

    }
    cout << ans << endl;
	return 0;
}