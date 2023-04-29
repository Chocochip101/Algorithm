import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        
        long[] parSum = new long[N];
        long[] res = new long[M];

        long ans = 0;
        st = new StringTokenizer(br.readLine());
        parSum[0] = Integer.parseInt(st.nextToken());
        for(int i = 1; i < N; ++i){
            parSum[i] = parSum[i - 1] + Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < N; ++i){
            if((int)(parSum[i] % M) == 0)
                ans++;

            res[(int)(parSum[i] % M)]++;
            
        }

        for(int i = 0; i < M; ++i){
            if(res[i] > 1)
            ans += (res[i] * (res[i] - 1)) / 2;
        }
        System.out.println(ans);
    }
}
