import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static boolean[] isPrime = new boolean[1010];

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> integers = Arrays.stream(bufferedReader.readLine().split(" ")).map(Integer::parseInt)
                .collect(Collectors.toList());
        Arrays.fill(isPrime, true);
        int cnt = 0;

        for (int i = 2; i <= integers.get(0); i++) {
            if (isPrime[i]) {
                for (int j = i; j <= integers.get(0); j += i) {
                    if (isPrime[j]) {
                        cnt++;
                        if (cnt == integers.get(1)) {
                            System.out.println( j);
                            return;
                        }
                    }
                    isPrime[j] = false;
                }
            }
        }
    }

}

