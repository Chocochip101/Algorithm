#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 51
#define MOD 1000000000
#define int ll
using namespace std;
typedef pair<int, int> p;

struct SegTree {
	int n;
	vector<int> rangeMin;
	SegTree(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}

	int init(const vector<int>& array, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = leftMin + rightMin;

	}


	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return 0;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
	}

	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index)
			return rangeMin[node];

		if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] =
			update(index, newValue, node * 2, nodeLeft, mid) +
			update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	}

	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >>m;
	vector<int> num;
	for (int i = 0; i < n; ++i) {
		num.push_back(0);
	}
	SegTree sg(num);

	for (int i = 0; i < m; ++i) {
		int ord, x, y; cin >> ord >> x >> y;
		if (ord == 0) {
			if (x > y) swap(x, y);
			cout << sg.query(x - 1, y - 1) << endl;
		}
		else if (ord == 1)
			sg.update(x - 1, y);
	}
}