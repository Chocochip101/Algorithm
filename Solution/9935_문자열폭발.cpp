#include <bits/stdc++.h>
#define endl "\n" 
#define ll long long
#define INF 987654321
#define MAX 3001
using namespace std;
typedef pair<int, int> p;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s, bomb; cin >> s >> bomb;
  
    string ans = "";
    for(int i = 0; i < s.size(); ++i){
        int idx = bomb.size() - 1;
        ans += s[i];
        if(ans.size() < bomb.size()) continue;
        int cnt = 0;
        if(bomb[idx] == ans[ans.size() - 1]){
            cnt = 1;
            for(int j = idx - 1; j>= 0; --j){
                if(bomb[j] == ans[ans.size() - (bomb.size() - j)]){
                    cnt++;
                }
            }
        }

        if(cnt == bomb.size())
            for(int j = 0; j < bomb.size(); ++j)
                ans.pop_back();
        
    }
    if(ans.size())
        cout << ans;
    else
        cout << "FRULA";
	return 0;
}