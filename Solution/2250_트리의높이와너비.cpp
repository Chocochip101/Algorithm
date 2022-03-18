#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 10001
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, root, idx;
vector<int> graph[MAX];
int l[MAX], r[MAX];
int arr[MAX];
void recursion(int now, int lev) {
	if(graph[now][0] != -1)
		recursion(graph[now][0], lev + 1);
	
	l[lev] = min(l[lev], idx);
	r[lev] = max(r[lev], idx++);
	
	if (graph[now][1] != -1)
		recursion(graph[now][1], lev + 1);
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < MAX; ++i)
		l[i] = INF;
	for (int i = 0; i < N; ++i) {
		int a, b, c; cin >> a >> b >> c;
		
		arr[a]++;

		if (b != -1)
			arr[b]++;
		graph[a].push_back(b);
		if (c != -1)
			arr[c]++;
		graph[a].push_back(c);

	}

	for (int i = 1; i <= N; ++i)
		if (arr[i] == 1)
			root = i;
	idx = 1;
	recursion(root, 1);

	int result = r[1] - l[1] + 1;
	int level = 1;
	for (int i = 2; i <= N; i++){
		if (r[i] - l[i] + 1 > result){
			result = r[i] - l[i] + 1;
			level = i;
		}
	}
	cout << level << " " << result << endl;

	return 0;
}