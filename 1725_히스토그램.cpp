#include <bits/stdc++.h>
#define INF 987654321
#define MAX 100001
using namespace std;
typedef pair<int, int> p;

using namespace std;

long long n;
long long seg[1000001];
long long x, ans;
long long h[100001];

int init(int node, int s, int e)
{
	if (s == e) return seg[node] = s; // start 와 end 의 위치가 일치하면 인덱스 s 값을 넣어준다.
	int mid = (s + e) / 2;
	int left_index = init(2 * node, s, mid);
	int right_index = init(2 * node + 1, mid + 1, e);

	return seg[node] =
		h[left_index] < h[right_index] ? left_index : right_index;
}

int query(int node, int s, int e, int l, int r)
{
	if (e < l || r < s) return INF; // 찾아야하는 구간과 노드구간이 겹치지 않을 때
	if (l <= s && e <= r) return seg[node]; // 찾아야하는 구간내에 노드구간이 포함될 때
	int mid = (s + e) / 2;
	int left_index = query(2 * node, s, mid, l, r);
	int right_index = query(2 * node + 1, mid + 1, e, l, r);

	// 찾아야하는 구간이 노드구간에 포함되거나, 부분적으로 겹치는 경우
	if (left_index == INF) return right_index; // 에러방지
	else if (right_index == INF) return left_index; // 에러방지
	else return h[left_index] < h[right_index] ? left_index : right_index;
}


void solve(long long left, long long right)
{
	if (left > right) return;

	// 구간내의 최소값과 해당 인덱스 찾기
	long long index = query(1, 0, n - 1, left, right); // 구간 내의 최소값 찾기

	ans = max(ans, h[index] * (right - left + 1));

	solve(left, index - 1);
	solve(index + 1, right);

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

		ans = 0;
		cin >> n;
		
		for (int i = 0; i < n; i++)
		{
			cin >> h[i];
		}
		init(1, 0, n - 1); // 세그먼트 트리 만들기
		solve(0, n - 1);

		cout << ans << endl;
	

}