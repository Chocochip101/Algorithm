import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static int[] dp = new int[100001];
    static int N;
    static final int INF = 987654321;

    public static void main(String[] args) throws Exception {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            N = Integer.parseInt(br.readLine());
            Arrays.fill(dp, -1);
            
            System.out.println(solve(N));
    }
    public static boolean isSquare(int n){
        return Math.floor(Math.sqrt(n)) == Math.sqrt(n);
    }
    public static int solve(int n){
        if(isSquare(n)){
            return 1;
        }
        if(n < 0){
            return INF;
        }
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = INF;

        for(int i = 1; i < Math.sqrt(n); i++){
            dp[n] = Math.min(dp[n], solve(n - i * i) + 1);
        }
        return dp[n];
    }
}
