#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 1000002
#define INF 987654321

using namespace std;

int N;
bool isPrime[MAX];
// 소수 찾기
void Prime(){
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;

    for(int i = 2; i <= sqrt(MAX); ++i){
        if(isPrime[i]){
            for(int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
}
// 상근수 변환
int changeNum(int num){
    int ans = 0;
    while(num > 0){
        ans += (num % 10) * (num % 10);
        num /= 10;
    }
    return ans;
}
// 상근수 판별
bool solve(int num){
    set<int> st;
    st.insert(num);

    while(num != 1){
        num = changeNum(num);
        if(st.find(num) != st.end())
            return false;
        else
            st.insert(num);
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(isPrime, true, sizeof(isPrime));

    Prime();
    cin >> N;

    for(int i = 1; i <=N; ++i)
        if(isPrime[i] && solve(i))
            cout << i << endl;
    return 0;
}