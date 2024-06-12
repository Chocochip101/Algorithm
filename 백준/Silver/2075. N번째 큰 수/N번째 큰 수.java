import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {


    static int N;

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Queue<Long> pq = new PriorityQueue<>();
        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < N; i++) {
            String[] split = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                pq.add(-Long.parseLong(split[j]));
            }
        }

        while(pq.size() != N * N - N + 1){
            pq.poll();
        }
        System.out.println(-pq.poll());
    }
}



