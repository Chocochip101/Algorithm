#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 10001
using namespace std;
typedef pair<int, int> p;

bool isPrime[MAX];
int dist[MAX];
void makePrime(){
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i <= int(sqrt(MAX)); ++i){
        if(isPrime[i])
            for(int j = i * i; j < MAX; j += i)
                isPrime[j] = false;
    }
}
int bfs(int a, int b){
    memset(dist, -1, sizeof(dist));
    queue<int> q; 
    q.push(a);
    dist[a] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == b) return dist[b];
        // a를 한자리씩 바꿈 1234
        // vc 1 2 3 4
        int temp = now;
        vector<int> vc;
        for(int i = 0; i < 4; ++i){
            vc.push_back(temp % 10);
            temp /= 10;
        }
        reverse(vc.begin(), vc.end());

        for(int i = 0; i < 4; ++i){
            for(int pos = 0; pos <= 9; ++pos){
                if(pos == vc[i]) continue;
                int next = 0;
                for(int j = 0; j < 4; ++j){
                    if(i == j)
                        next += pow(10, 3 - j) * pos;
                    else
                        next += pow(10, 3 - j) * vc[j];
                }
                if( next < 10000 && next >= 1000 && dist[next] == -1 && isPrime[next]){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(isPrime, true, sizeof(isPrime));
    makePrime();
    int tc;cin>> tc;
    while(tc--){
        int a, b; cin >> a >> b;
        int ans = bfs(a, b);
        if(ans == -1)
            cout << "Impossible" << endl;
        else 
            cout << ans << endl;
    }
	return 0;
}