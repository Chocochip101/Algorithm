#include <bits/stdc++.h>
#define endl "\n"
#define MAX  1501
using namespace std;
typedef pair<int, int> p;

int N; 
priority_queue<int> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N * N; ++i){
        int a; cin >> a;
        pq.push(-a);
        if(pq.size() > N)
            pq.pop();
    }
    cout << -pq.top();
	return 0;
}