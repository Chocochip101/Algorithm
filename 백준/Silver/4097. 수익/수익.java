import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int N;
    static int[] cache;
    static int[] numbers;

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            N = Integer.parseInt(br.readLine());
            if (N == 0) {
                return;
            }
            numbers = new int[N];
            cache = new int[N];
            Arrays.fill(cache, 0);

            for (int i = 0; i < N; i++) {
                numbers[i] = Integer.parseInt(br.readLine());
            }

            cache[0] = numbers[0];
            for (int i = 1; i < N; i++) {
                if (cache[i - 1] + numbers[i] < numbers[i]) {
                    cache[i] = numbers[i];
                } else {
                    cache[i] = cache[i - 1] + numbers[i];
                }
            }

            int ans = cache[0];
            for (int i = 0; i < N; i++) {
                ans = Math.max(ans, cache[i]);
            }

            System.out.println(ans);
        }
    }
}


