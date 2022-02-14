#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define INF 987654321
#define MAX 100001
#define int ll
using namespace std;
typedef pair<int, int> p;

int N, M;
int lev[MAX];
priority_queue<p> pq1;
priority_queue<p, vector<p>, greater<p>> pq2;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    memset(lev, -1, sizeof(lev));
    cin >> N;
    for(int i = 0; i < N; ++i){
        int P, L; cin >> P >>L;
        pq1.push({L, P});
        pq2.push({L, P});
        lev[P] = L;
    }

    cin >> M;
    for(int i = 0; i < M; ++i){
        string com; cin >> com;
        if(com == "recommend"){
            int x; cin >> x;
            if(x == -1){
                while(lev[pq2.top().second] != pq2.top().first) pq2.pop();
                cout << pq2.top().second << endl;
            }else if(x == 1){
                while(lev[pq1.top().second] != pq1.top().first) pq1.pop();
                cout << pq1.top().second << endl;
            }
        }
        else if(com == "add"){
            int L, P; cin >> P >> L;
            lev[P] = L;
            pq1.push({L, P});
            pq2.push({L, P});
        }
        else if(com == "solved"){
            int P; cin >> P;
            lev[P] = -1;
        }
    }
	return 0;
}