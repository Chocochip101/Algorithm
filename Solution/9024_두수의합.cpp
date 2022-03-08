#include <bits/stdc++.h>
#define endl "\n"
#define MAX 1000001
#define INF 987654321
using namespace std;

int N, K;
int arr[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--){ 
        cin >> N >> K;
        for(int i = 0; i < N; ++i)
            cin >> arr[i];
        
        sort(arr, arr + N);
        int cnt = 0;
        int minRes = INF;
        int l = 0, r = N - 1;
        while(l < r){
            int le = arr[l];
            int ri = arr[r];
            if(le + ri == K){
                l++; r--;
            }else if(le + ri > K){
                r--;
            }
            else{
                l++;
            }
                
            if(abs(K - (le+ri)) < minRes){
                minRes = abs(K - (le+ri));
                cnt = 1;
            }else if(abs(K - (le+ri)) == minRes)
                cnt++;
        }
        
        cout << cnt << endl;
    }

	return 0;
}