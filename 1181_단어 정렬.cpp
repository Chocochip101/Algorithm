#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<string> words;

bool compare(string x, string y) {
	if (x.size() == y.size()) return x < y;
	return x.size() < y.size();
}
int main() {
	int n;
	cin >> n;
	words.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> words[i];
	//����
	sort(words.begin(), words.end(), compare);
	//�ߺ� ����
	words.erase(unique(words.begin(), words.end()), words.end());

	for (int i = 0; i < words.size(); ++i)
		cout << words[i] << endl;
	return 0;
}