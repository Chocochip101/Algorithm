import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class Main {

    static boolean[] finished;
    static Map<Character, Integer> dir = new HashMap<>();
    static int answer = 0;

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String movement = br.readLine();
        finished = new boolean[N];

        dir.put('E', 1);
        dir.put('W', -1);

        for (int i = 0; i < N; i++) {
            Queue<Integer> queue = new LinkedList<>();
            boolean[] visited = new boolean[N];
            queue.add(i);

            while (!queue.isEmpty()) {
                int now = queue.poll();
                if (finished[now]) {
                    break;
                }
                if (visited[now]) {
                    answer++;
                    break;
                }
                visited[now] = true;

                queue.add(now + dir.get(movement.charAt(now)));
            }
            for (int j = 0; j < N; j++) {
                if (visited[j]) {
                    finished[j] = true;
                }
            }
        }
        System.out.println(answer);

    }

}


