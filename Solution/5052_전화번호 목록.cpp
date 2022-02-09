#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10;

struct TrieNode {
	TrieNode* children[MAX];
	bool terminal;
	TrieNode() :terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < MAX; i++)
			if (children[i])
				delete children[i];
	}
	int toNum(char ch) {
		return ch - '0';
	}
	bool insert(const char* key) {
		if (terminal) return false;
		if (*key == '\0')
			terminal = true;
		else {
			int next = toNum(*key);
			if (!children[next])
				children[next] = new TrieNode;
			return children[next]->insert(key + 1);
		}
		return true;
	}
};

bool check(const vector<string>& v) {
	TrieNode trie;
	for (string s : v)
		if (!trie.insert(s.c_str()))
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<string> v(N);
		for (string& s : v)
			cin >> s;
		sort(v.begin(), v.end());
		if (check(v))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}