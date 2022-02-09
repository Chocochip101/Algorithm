#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MAX 333
#define INF 987654321

using namespace std;
typedef pair<int, int> p;

int A, B, C, N;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    bool flag = false;
    cin >> A >> B >> C >>N;
    for(int i = 0; i <MAX; ++i)
        for(int j = 0; j <MAX;++j)
            for(int k = 0; k <MAX; ++k)
                if(i * A + j * B + k * C == N)
                {
                    flag = true;
                    break;
                }
    if(flag)
        cout << 1;
    else 
        cout << 0;
    return 0;
}