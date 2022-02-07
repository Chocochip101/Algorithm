#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 500001
#define INF 987654321
#define MOD 1000000009
#define int ll
using namespace std;
typedef pair<int, int> p;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while (tc--) {
        deque<char> right, left;
        string s; cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '<') {
                if (!right.empty()) {
                    left.push_front(right.back());
                    right.pop_back();
                }
            }
            else if (s[i] == '>') {
                if (!left.empty()) {
                    right.push_back(left.front());
                    left.pop_front();
                }
            }

            else if (s[i] == '-') {
                if (!right.empty())
                    right.pop_back();
            }
            else right.push_back(s[i]);
              
        }


        while (!right.empty()) {
            cout << right.front();
            right.pop_front();
        }
        while (!left.empty()) {
            cout << left.front();
            left.pop_front();
        }
        cout << endl;
    }
    return 0;
}