import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

    static int N;
    static int M;
    static boolean[] flag = new boolean[10];
    static int[] arr = new int[10];
    static StringBuilder sb = new StringBuilder();

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> NM = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        N = NM.get(0);

        M = NM.get(1);

        solve(0);
        System.out.println(sb);
    }

    static void solve(int cnt) {
        if (cnt == M) {
            for (int i = 0; i < M; i++) {
                sb.append(arr[i]);
                sb.append(" ");
            }
            sb.append("\n");
            return;
        }

        for (int i = 1; i <= N; i++) {
            flag[i] = true;
            arr[cnt] = i;
            solve(cnt + 1);
            flag[i] = false;
        }
    }
}
