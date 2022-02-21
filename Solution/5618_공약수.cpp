#include<bits/stdc++.h>
#define ll long long
#define INF 987654321
#define MAX 4002
using namespace std; 
typedef pair<int, double> p;

int N;
int arr[MAX];

int solve(int a, int b){
    if(a > b) swap(a, b);
    if(b % a == 0) return a;
    return solve(b % a, a);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> arr[i];
    int gcd = arr[0];

    for(int i = 1; i < N; ++i)
        gcd = solve(gcd, arr[i]);

    for(int i = 1; i <= gcd; i++)
        if(gcd % i == 0)
            cout <<  i << endl;
    return 0;
}