import java.util.*;

class Solution {
    public static long[] dp = new long[100_001];
    public static long MOD = 1_000_000_007;
    
    public long solution(int n) {
        Arrays.fill(dp, -1);
        return solve(n);
    }
    
    public long solve(int n){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 3;
        }
        if(n == 3){
            return 10;
        }
        if(n == 4){
            return 23;
        }
        if(n == 5){
            return 62;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = (solve(n - 1) + (solve(n - 2) * 2) + (solve(n - 3) * 6) + solve(n - 4) - solve(n - 6) + MOD) % MOD;
        return dp[n];
    }
}