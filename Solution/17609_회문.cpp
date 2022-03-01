#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1000001
using namespace std;
typedef pair<int, int> p;

bool chkPld(string s, int l, int r){
    if(l >= r) return true;
    while(l < r){
        if(s[l] != s[r])
            return false;
        l++; r--;
    }
    return true;
}
int solve(string s){
    bool isPld = true;
    bool isSimPld = false;
    int l = 0, r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]){
            isPld = false;
            if(chkPld(s, l + 1, r)){
                isSimPld = true;
                break;
            }            
            if(chkPld(s, l, r - 1)){
                isSimPld = true;
                break;
            }
            break;
        }
        l++; r--;
    }

    if(isPld) return 0;
    else if(isSimPld) return 1;
    else return 2;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--){
        string s; cin >> s;
        cout <<solve(s)<< endl;
    }
	return 0;
}