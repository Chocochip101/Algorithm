#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define loop(i, n) for(int i = 0; i <n;++i)
#define INF 987654321
#define MAX_V 20000 + 1
using namespace std;
typedef pair<int, int> p;

int v, e, k;
//(node, dest)
vector<p> graph[MAX_V];
vector<int> dijkstra(int src) {
	priority_queue<p> pq;
	vector<int> dist(v, INF);
	dist[src] = 0;
	pq.push({ 0, src });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (cost > dist[now]) continue;
		loop(i, graph[now].size()) {
			int here = graph[now][i].first;
			int nextDist = cost + graph[now][i].second;
			if (dist[here] > nextDist) {
				dist[here] = nextDist;
				pq.push({ -nextDist, here });
			}
		}
	}
	return dist;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);

	cin >> v >> e;
	cin >> k;
	loop(i, e) {
		int start, destination, cost;
		cin >> start >> destination >> cost;
		graph[start - 1].push_back({ destination - 1, cost });
	}

	vector<int> dist = dijkstra(k - 1);

	loop(i, v) {
		if (dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	return 0;
}