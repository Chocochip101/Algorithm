#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 100001
using namespace std;

int n, k;
int visited[MAX];
typedef pair<int, int> p;

//°Å¸®, point
priority_queue<p, vector<p>, greater<p>> q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	memset(visited, -1, sizeof(visited));
	visited[n] = 0;
	q.push({ 0, n });

	while (!q.empty()) {
		int cost = q.top().first;
		int now = q.top().second;

		q.pop();
		if (now == k) break; 
		if (2 * now < MAX && visited[2 * now] == -1) {
			q.push({ cost, 2 * now });
			visited[2 * now] = cost;
		}
		if (now + 1 < MAX && visited[now + 1] == -1) {
			q.push({ cost + 1,now + 1 });
			visited[now + 1] = cost + 1;
		}
		if (now - 1 >= 0 && visited[now - 1] == -1) {
			q.push({ cost + 1, now - 1 });
			visited[now - 1] = cost + 1;
		}
		
	}
	cout << visited[k] << endl;
	return 0;
}