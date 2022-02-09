#include<bits/stdc++.h>
#define ll long long
#define INF 987654321
#define MAX 4002
using namespace std; 
typedef pair<int, double> p;

string s1, s2;
int cache[MAX][MAX] = {0,};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;
  
    int res = 0;
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                cache[i][j] = cache[i - 1][j - 1] + 1;
                res = max(cache[i][j], res);
            }
        }
    }
    cout << res;
    return 0;
}