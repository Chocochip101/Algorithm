#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;

//tree[node][left or right]
char tree[26][2];

void preOrder(char root) {
	if (root == '.')
		return;
	cout << root;
	preOrder(tree[root - 'A'][0]);
	preOrder(tree[root - 'A'][1]);
}

void inOrder(char root) {
	if (root == '.') return;
	inOrder(tree[root - 'A'][0]);
	cout << root;
	inOrder(tree[root - 'A'][1]);
}

void postOrder(char root) {
	if (root == '.') return;
	postOrder(tree[root - 'A'][0]);
	postOrder(tree[root - 'A'][1]);
	cout << root;
}

int main() {
	cin >> n;
	char a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		tree[a - 'A'][0] = b;
		tree[a - 'A'][1] = c;
	}

	preOrder('A');
	cout << endl;
	inOrder('A');
	cout << endl;
	postOrder('A');
	return 0;
}