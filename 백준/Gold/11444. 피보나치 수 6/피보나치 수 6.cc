#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<long long, long long> memo;

long long MOD = 1000000007;


long long doganu(long long  n){
	
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        memo[1]=1;
		return 1;
    } else if (n == 2) {
		memo[2]=1;
        return 1;
    } else if (memo.count(n) > 0) {
        return memo[n];
    }
	else{
	if(n % 2 == 0){
		long long a = doganu(n / 2 - 1);
		long long b = doganu(n / 2);

		memo[n] = (2 * a + b)% MOD * b % MOD;
		return memo[n] % MOD;
	}
	else{
		
		long long a = doganu(n / 2 + 1);
		long long b = doganu(n / 2);
		memo[n] = (a * a) % MOD + (b * b) % MOD;
		
		return memo[n] % MOD;
	}
		
	}
	
}

int main() {
	
	long long n;
	cin>>n;
	cout<<doganu(n);
	
	return 0;

}