#include <bits/stdc++.h>
#define INF 987654321
#define MAX 200000
#define ll long long
using namespace std;
typedef pair<int, int> p;

int N, K;
int tr[MAX];
int dist[MAX];
queue<int> q;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	memset(tr, -1, sizeof(tr));

	q.push(N);
	dist[N] = 0;
	tr[N] = INF;
	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (now == K) {
			break;
		}
		if (now - 1 >= 0 && tr[now - 1] == -1) {
			tr[now - 1] = now;
			dist[now - 1] = dist[now] + 1;
			q.push(now - 1);
		}
		if (now + 1 < MAX && tr[now + 1] == -1) {
			tr[now + 1] = now;
			dist[now + 1] = dist[now] + 1;
			q.push(now + 1);
		}
		if (now * 2 < MAX &&tr[now * 2] == -1) {
			tr[now * 2] = now;
			dist[now * 2] = dist[now] + 1;
			q.push(now * 2);
		}

	}
	cout << dist[K] << endl;

	stack<int> ans;
	for (int i = K; i != INF; i = tr[i])
		ans.push(i);

	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
	return 0;

}