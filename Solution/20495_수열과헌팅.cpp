#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 500001
using namespace std;

int N;
int small[MAX], big[MAX];
vector<int> l, r;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; ++i){
		int a, b; cin >> a >> b;
		small[i] = a - b;
		big[i] = a + b;
		l.push_back(a - b);
		r.push_back(a + b);
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	for(int i = 0; i < N; ++i)
		cout << lower_bound(r.begin(), r.end(), small[i]) - r.begin() + 1 << " " << upper_bound(l.begin(), l.end(), big[i]) - l.begin() << endl;
	
	return 0;
}