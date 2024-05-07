import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

    static List<Integer> NAndK;
    static int[] weight;
    static int[] values;

    static int[][] cache;

    public static void main(String... args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        NAndK = Arrays.stream(bf.readLine().split(" ")).map(Integer::parseInt)
                .collect(Collectors.toList());
        weight = new int[NAndK.get(0)];
        values = new int[NAndK.get(0)];
        cache = new int[NAndK.get(0)][NAndK.get(1) + 1];

        for (int i = 0; i < NAndK.get(0); i++) {
            String[] split = bf.readLine().split(" ");
            weight[i] = Integer.parseInt(split[0]);
            values[i] = Integer.parseInt(split[1]);

            Arrays.fill(cache[i], -1);
        }

        System.out.println(solve(0, NAndK.get(1)));
    }

    static int solve(int n, int k) {
        if (n >= NAndK.get(0)) {
            return 0;
        }
        if (cache[n][k] != -1) {
            return cache[n][k];
        }

        cache[n][k] = solve(n + 1, k);

        if (k >= weight[n]) {
            cache[n][k] = Math.max(cache[n][k], solve(n + 1, k - weight[n]) + values[n]);
        }
        return cache[n][k];
    }
}


