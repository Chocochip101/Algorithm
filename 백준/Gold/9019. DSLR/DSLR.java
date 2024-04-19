import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.stream.Collectors;

public class Main {
    public static class P {
        public int number;
        public String order;

        public P(final int number, final String order) {
            this.number = number;
            this.order = order;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(bf.readLine());
        for (int i = 0; i < T; i++) {
            List<Integer> integers = Arrays.stream(bf.readLine().split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());
            System.out.println(solve(integers.get(0), integers.get(1)));
        }
    }

    public static String solve(int A, int B) {
        Queue<P> queue = new LinkedList<>();
        boolean[] visited = new boolean[10_010];
        Arrays.fill(visited, false);
        queue.add(new P(A, ""));
        visited[A] = true;

        while (!queue.isEmpty()) {
            P now = queue.poll();
            if (now.number == B) {
                return now.order;
            }

            //D
            int next = (now.number * 2) % 10000;
            if (!visited[next]) {
                visited[next] = true;
                queue.add(new P(next, now.order + "D"));
            }
            //S
            next = now.number == 0 ? 9999 : now.number - 1;
            if (!visited[next]) {
                visited[next] = true;
                queue.add(new P(next, now.order + "S"));
            }
            //L
            next = nextL(now.number);
            if (!visited[next]) {
                visited[next] = true;
                queue.add(new P(next, now.order + "L"));
            }
            //R
            next = nextR(now.number);
            if (!visited[next]) {
                visited[next] = true;
                queue.add(new P(next, now.order + "R"));
            }

        }
        return "";
    }

    static int nextL(int number) {
        String str = String.valueOf(number);
        while (str.length() < 4) {
            str = "0" + str;
        }
        return Integer.parseInt(str.substring(1, 4) + str.charAt(0));
    }

    static int nextR(int number) {
        String str = String.valueOf(number);
        while (str.length() < 4) {
            str = "0" + str;
        }
        return Integer.parseInt(str.charAt(3) + str.substring(0, 3));
    }
}

