#include <bits/stdc++.h>
#define endl "\n"
#define start first
#define fin second
using namespace std;
typedef pair<int, int> p;
vector<p> vc;
bool compare(const p& a, const p& b) {
	if (a.fin == b.fin) return a.start < b.start;
	return a.fin < b.fin;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int start, end;
		cin >> start >> end;
		vc.push_back({ start, end });
	}
	sort(vc.begin(), vc.end(), compare);
	int res = 1;
	int min_end = vc[0].fin;
	for (int i = 1; i < n; ++i) {
		if (min_end <= vc[i].start) {
			res++;
			min_end = vc[i].fin;
		}
	}
	cout << res;
	return 0;
}