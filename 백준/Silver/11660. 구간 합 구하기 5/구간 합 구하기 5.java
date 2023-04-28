import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        int[][] numbers = new int[N + 1][N + 1];
        int[][] parSum = new int[N + 1][N + 1];
        
        for(int i = 1; i <= N; ++i){
            st = new StringTokenizer(br.readLine());

            for(int j = 1; j <= N; ++j)
                numbers[i][j] = Integer.parseInt(st.nextToken());
        }
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= N; ++j){
                parSum[i][j] = parSum[i - 1][j] + parSum[i][j - 1] - parSum[i - 1][j - 1] + numbers[i][j];
            }
        }
        
        for(int i = 0; i < M; ++i){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            System.out.println(parSum[c][d] - parSum[c][b - 1] - parSum[a - 1][d] + parSum[a - 1][b - 1]);
        }
    }
}
