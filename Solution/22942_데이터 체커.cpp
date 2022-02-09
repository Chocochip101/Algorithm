#include<bits/stdc++.h>
#define endl "\n"
#define MAX 2020001
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;
struct coord {
	int val, isOpen, idx;
};
bool cmp(coord a, coord b) { return a.val < b.val; }
int N;
vector<coord> vc;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int x, r; cin >> x >> r;
		vc.push_back({ x - r, 0, i });
		vc.push_back({ x + r, 1, i });
	}
	sort(vc.begin(), vc.end(),cmp);
	bool flag = true;
	stack<int> stk;
	for (coord P : vc) {
		if (P.isOpen == 0)
			stk.push(P.idx);

		else{
			if (P.idx == stk.top())
				stk.pop();
			else { 
				flag = false; 
				break;
			}
		}
	}
	if (flag)
		cout << "YES";
	else cout << "NO";
	return 0;
}