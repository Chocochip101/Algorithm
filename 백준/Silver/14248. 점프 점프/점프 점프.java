import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static int N;
    static int S;
    static boolean[] visited;
    static int cnt = 0;
    static List<Integer> jumps;

    public static void main(String... args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        visited = new boolean[N];
        jumps = Arrays.stream(bf.readLine().split(" ")).map(Integer::parseInt)
                .collect(Collectors.toList());

        S = Integer.parseInt(bf.readLine()) - 1;
        dfs(S);
        System.out.println(cnt);
    }

    static void dfs(int start) {
        visited[start] = true;
        cnt++;

        if (isValid(start - jumps.get(start)) && !visited[start - jumps.get(start)]) {
            dfs(start - jumps.get(start));
        }

        if (isValid(start + jumps.get(start)) && !visited[start + jumps.get(start)]) {
            dfs(start + jumps.get(start));
        }
    }

    static boolean isValid(int x) {
        return 0 <= x && x < N;
    }
}


