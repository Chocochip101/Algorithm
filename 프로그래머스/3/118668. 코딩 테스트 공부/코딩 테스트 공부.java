import java.util.*;

class Solution {
    public static int maxAlp = -1;
    public static int maxCop = -1;
    public static int[][] dp = new int[1001][1001];
    public static int INF = 987654321;
    public int solution(int alp, int cop, int[][] problems) {
      for (int[] problem : problems) {
            maxAlp = Math.max(maxAlp, problem[0]);
            maxCop = Math.max(maxCop, problem[1]);
        }

        dp = new int[Math.max(alp, maxAlp) + 1][Math.max(cop, maxCop) + 1];

        for (int i = 0; i <= Math.max(alp, maxAlp); i++) {
            Arrays.fill(dp[i], INF);
        }

        return solve(alp, cop, problems);
    }
    
    static int solve(int alp, int cop, int[][] problems){
        if(alp >= maxAlp && cop >= maxCop){
            return 0;
        }
        if(dp[alp][cop] != INF){
            return dp[alp][cop];
        }
        dp[alp][cop] = INF + 1;
        for(int i = 0; i < problems.length; ++i){
            if(alp >= problems[i][0] && cop >= problems[i][1]){
                dp[alp][cop] = Math.min(dp[alp][cop], problems[i][4] + solve(Math.min(alp + problems[i][2], maxAlp), Math.min(cop + problems[i][3], maxCop), problems));
            }
        }
        
        dp[alp][cop] = Math.min(dp[alp][cop], 1 + solve(Math.min(alp + 1, maxAlp), cop, problems));
        dp[alp][cop] = Math.min(dp[alp][cop], 1 + solve(alp, Math.min(cop + 1, maxCop), problems));

        return dp[alp][cop];
    }
}