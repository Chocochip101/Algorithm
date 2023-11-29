import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static int[][] dp = new int[2020][2020];
    static int S;
    static final int INF = 987654321;

    public static void main(String[] args) throws Exception {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            S = Integer.parseInt(br.readLine());
            for(int[] arr: dp){
                Arrays.fill(arr, -1);
            }

            System.out.println(solve(1, 0));
    }
    public static int solve(int emoticon, int clip){
        if(emoticon > 2 * S || clip > 2 * S){
            return INF;
        }
        if(emoticon < 0){
            return INF;
        }
        if(emoticon == S){
            return 0;
        }
        if(dp[emoticon][clip] != -1){
            return dp[emoticon][clip];
        }

        dp[emoticon][clip] = INF;
        dp[emoticon][clip] = Math.min(dp[emoticon][clip], solve(emoticon, emoticon) + 1);
        dp[emoticon][clip] = Math.min(dp[emoticon][clip], solve(emoticon + clip, clip) + 1);
        dp[emoticon][clip] = Math.min(dp[emoticon][clip], solve(emoticon - 1, clip) + 1);
        return dp[emoticon][clip];
    }
}
