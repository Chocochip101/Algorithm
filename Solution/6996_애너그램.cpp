#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 31
using namespace std;
typedef pair<int, int> p;

int A[27], B[27];
bool solve(string a, string b){
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));

    for(int i = 0; i < a.size(); ++i)
        A[a[i] - 'a']++;
    for(int i = 0; i < b.size(); ++i)
        B[b[i] - 'a']++;
    bool flag = true;
    for(int i = 0; i < 27; ++i)
        if(A[i] !=  B[i])
            flag = false;
    return flag;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--){
        string a, b;
        cin >> a >> b;
        if(solve(a, b))
            cout << a << " & " << b << " are anagrams."<< endl;
        else 
            cout << a << " & " << b << " are NOT anagrams." << endl;
    }
	return 0;
}