#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 201
using namespace std;
typedef pair<int, int> p;

int A, B, C;
bool visited[MAX][MAX][MAX];
vector<int> solve() {
	queue<pair<int, p>> q;
	q.push({ 0, {0, C} });
	vector<int> ans;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;
		if (a == 0) ans.push_back(c);

		//a->b
		if (a + b > B)
			q.push({ a + b - B, {B, c} });
		else
			q.push({ 0, {a + b, c} });

		//a->c
		if (a + c > C)
			q.push({ a + c - C, {b, C} });
		else
			q.push({ 0, {b, a + c} });

		//b->a
		if (a + b > A)
			q.push({ A, {a + b - A, c} });
		else
			q.push({ a + b, {0, c} });

		//b->c
		if (c + b > C)
			q.push({ a, {b + c - C, C} });
		else
			q.push({ a, {0, b + c} });

		//c->a
		if (a + c > A)
			q.push({ A, {b , c + a - A} });
		else
			q.push({ a + c, {b, 0} });
			
		//c->b
		if (c + b > B)
			q.push({ a , {B, c + b - B} });
		else
			q.push({ a, {c + b, 0} });
	}

	return ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;
	memset(visited, false, sizeof(visited));
	vector<int> ans = solve();
	sort(ans.begin(), ans.end());
	for (int a : ans)
		cout << a << " ";
	return 0;
}