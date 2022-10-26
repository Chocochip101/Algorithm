#include <iostream>
#include <vector>
#define tall first
#define weight second
using namespace std;

typedef pair<int, int> p;

int main() {
	int n; cin >> n;

	vector<p> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	for (int i = 0; i < n; i++) {
		int rank = 1;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if ((v[i].tall < v[j].tall) && (v[i].weight < v[j].weight))
				rank++;
		}
		cout << rank << " ";
	}
	cout << endl;
	return 0;
}