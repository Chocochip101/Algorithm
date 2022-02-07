#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void print_vec(int m, vector<int>& a) {
	for (int i = 0; i < m; ++i)cout << a[i] << ' ';
	cout << endl;
}
void print_comb(int n, int m, int start, vector<int>& selected) {

	//기저 사례 1
	if (selected.size() == m) print_vec(m, selected);

	//기저 사례 2
	else if (start > n) return;


	else {
		//start숫자 포함
		selected.push_back(start);
		print_comb(n, m, start + 1, selected);

		//start숫자 제외
		selected.pop_back();
		print_comb(n, m, start + 1, selected);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int n, m;
	vector<int> v;
	cin >> n >> m;

	print_comb(n, m, 1, v);
	return 0;
}