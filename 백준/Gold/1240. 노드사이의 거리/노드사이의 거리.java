import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static int[][] graph = new int[1010][1010];
    static boolean[] visited = new boolean[1010];

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> NAndM = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt).collect(Collectors.toList());

        for (int i = 0; i < 1010; i++) {
            Arrays.fill(graph[i], -1);
        }

        for (int i = 0; i < NAndM.get(0) - 1; i++) {
            List<Integer> input = Arrays.stream(br.readLine().split(" "))
                    .map(Integer::parseInt).collect(Collectors.toList());
            graph[input.get(0)][input.get(1)] = input.get(2);
            graph[input.get(1)][input.get(0)] = input.get(2);
        }

        for (int i = 0; i < NAndM.get(1); i++) {
            List<Integer> input = Arrays.stream(br.readLine().split(" "))
                    .map(Integer::parseInt).collect(Collectors.toList());
            Arrays.fill(visited, false);
            System.out.println(dist(input.get(0), input.get(1), 0));
        }
    }

    static int dist(int src, int dest, int dd) {
//        System.out.println(src + ", " + dest + ", " + dd);
        if (src == dest) {
            return dd;
        }
        int result = 987654321;
        for (int i = 1; i < 1010; i++) {
            if (graph[src][i] != -1 && !visited[i]) {
                visited[i] = true;
                result = Math.min(result, dist(i, dest, dd + graph[src][i]));
                visited[i] = false;
            }
        }
        return result;
    }
}



