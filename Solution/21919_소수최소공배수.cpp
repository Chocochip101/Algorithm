#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 10001
#define PRIMEMAX 1000001
#define int ll
using namespace std;

int N;
int A[MAX];
bool isPrime[PRIMEMAX];
void prime(){
    isPrime[2] = true;
    for(int i = 2; i < sqrt(PRIMEMAX); ++i)
        if(isPrime[i])
            for(int j = i * i; j < PRIMEMAX; j += i)
                isPrime[j] = false;
}
// 6 8
int LCA(int a, int b){
    if(b % a == 0) return a;
    return LCA(b % a, a);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(isPrime, true, sizeof(isPrime));
    prime();
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];
    int cnt = 0;
    int ans = -1;
    for(int i = 0; i < N; ++i){
        if(isPrime[A[i]]){
            cnt++;
            if(ans == -1)
                ans = A[i];
            else{
                ans = (ans * A[i]) / LCA(ans, A[i]);
            }
        }
    }
    if(cnt == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;
	return 0;
}