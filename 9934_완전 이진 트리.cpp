#include <bits/stdc++.h>
#define endl "\n"
#define loop(i, n) for(int i = 0; i <n; ++i) 
#define ll long long
#define INF 987654321
#define MAX 3001
using namespace std;
typedef pair<int, int> p;

int k;
int num[1024];
vector<int> tree[11];

void solve(int src, int end, int level) {
	//±âÀú »ç·Ê
	if (src > end) return;

	int mid = (src + end) / 2;
	tree[level].push_back(num[mid]);


	solve(src, mid - 1, level + 1);
	solve(mid + 1, end, level + 1);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> k;
	for (int i = 1; i <= pow(2, k) - 1; ++i) cin >> num[i];

	solve(1, pow(2, k) - 1, 1);

	for (int i = 1; i <= k; ++i) {
		for (int n : tree[i]) {
			cout << n << " ";
		}cout << endl;
	}
	return 0;
}