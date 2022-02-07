#include<bits/stdc++.h>
#define endl "\n"
#define MAX 200050002
#define ll long long
using namespace std;
typedef pair<int, int> p;

const int BB = MAX / 2 ;
int N, K;
queue<int> q;
bool dist[MAX];
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dist, false, sizeof(dist));
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		a += BB;
		dist[a] = true;
		q.push(a);
	}
	int dis = 0;
	int tt = 0;
	ll ans = 0;
	while (!q.empty()) {
		if (tt == K) break;
		int q_size = q.size();
		dis++;
		for (int j = 0; j < q_size; ++j) {
			int now = q.front(); q.pop();

			if (0 <= now - 1 && !dist[now - 1]) {
				dist[now - 1] = true;
				tt++;
				ans += dis;
				if (tt == K) break;
				q.push(now - 1);
			}
			if (now + 1 < MAX && !dist[now + 1]) {
				dist[now + 1] = true;
				tt++;
				ans += dis;
				if (tt == K) break;
				q.push(now + 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}