import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input =  br.readLine().split(" ");

        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        
        int[] numbers = Arrays.stream(br.readLine().split(" "))
                          .mapToInt(Integer::parseInt)
                          .toArray();

        long[] parSum = new long[N+1];
        for(int i  = 1; i <= N; ++i){
            parSum[i] = parSum[i - 1] + numbers[i - 1];
        }

        for(int i=0; i <M; ++i){
            String[] inputM = br.readLine().split(" ");
            System.out.println(parSum[Integer.parseInt(inputM[1])] - parSum[Integer.parseInt(inputM[0]) - 1]);
        }
    }
}
