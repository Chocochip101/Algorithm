import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static long N;
    static long K;
    static int[] kArray;
    static int[] array;
    static long ans;

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Long> NK = Arrays.stream(br.readLine().split(" "))
                .map(Long::parseLong)
                .collect(Collectors.toList());
        N = NK.get(0);
        array = new int[String.valueOf(N).length()];
        K = NK.get(1);
        kArray = Arrays.stream(br.readLine().split(" "))
                .sorted()
                .mapToInt(Integer::parseInt)
                .toArray();
        for (int i = 0; i < String.valueOf(N).length() - 1; i++) {
            ans += kArray[(int) K - 1];
            ans *= 10;
        }
        ans /= 10;
        dfs(0);

        System.out.println(ans);
    }

    static void dfs(int idx) {

        if (idx == String.valueOf(N).length()) {
            int temp = 0;
            for (int i = 0; i < String.valueOf(N).length(); i++) {
                temp += array[i];
                temp *= 10;
            }
            temp /= 10;

            if(temp <= N){
                ans = Math.max(ans, temp);
            }
            return;
        }

        for (int i = 0; i < K; i++) {
            array[idx] = kArray[i];
            dfs(idx + 1);
        }
    }
}
