#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 1001
#define MOD 10007
using namespace std;

typedef pair<int,int> p;

int N;
int col[MAX];
int firstIdx = MAX, lastIdx = 0;
int longestIdx = 0;

int solve(){
    stack<int> stk;
    int result = 0;

    //오름차순 계산
    for(int i = firstIdx; i <=longestIdx; ++i){
        if(col[i] != -1){
            if(stk.empty()) stk.push(col[i]);
            else if(stk.top() < col[i]) 
                stk.push(col[i]);
        }
        result += stk.top();
        
    }    
    
    // Clear stack
    while(!stk.empty()) stk.pop();

    // 내림차순 계산
    for(int i = lastIdx; i >longestIdx; --i){
        if(col[i] != -1){
            if(stk.empty()) stk.push(col[i]);
            else if(stk.top() < col[i]) 
                stk.push(col[i]);
        }
        result += stk.top();   
    }
    return result;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(col, -1, sizeof(col));

    cin >> N;
    for(int i = 0;i <N; ++i){
        int idx, h; cin >> idx >> h;
        col[idx] = h;
        firstIdx = min(firstIdx, idx);
        lastIdx = max(lastIdx, idx);
        if(h > col[longestIdx]){
            longestIdx = idx;
        }
    }
    cout << solve();
	return 0;
}