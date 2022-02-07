#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1000000000
#define INF 987654321
#define MOD 1001
#define ll long long
#define int ll
using namespace std;
typedef pair<int, int> p;


signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	multiset<string> st;
	for (int i = 0; i < N; ++i) {
		string temp; cin >> temp;
		st.insert(temp);
	}
	string ans = "";
	for (int i = 0; i < N - 1; ++i) {
		string temp; cin >> temp;
		st.erase(st.find(temp));
		
		
	}
	cout << *st.begin();
	return 0;
}