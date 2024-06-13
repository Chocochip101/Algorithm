import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

    static class Numbers implements Comparable<Numbers> {
        int number;
        boolean isPlus;

        public Numbers(int number, boolean isPlus) {
            this.number = number;
            this.isPlus = isPlus;
        }

        public int getNumber() {
            return number;
        }

        public boolean isPlus() {
            return isPlus;
        }

        @Override
        public int compareTo(Numbers o) {
            if (this.number < o.getNumber()) {
                return -1;
            } else if (this.number == o.getNumber()) {
                if (this.isPlus()) {
                    return 1;
                }
                return -1;
            }
            return 1;
        }

        @Override
        public String toString() {
            if (isPlus) {
                return String.valueOf(number);
            }
            return "-" + number;
        }
    }

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Queue<Numbers> pq = new PriorityQueue<>();

        for (int i = 0; i < N; i++) {
            int input = Integer.parseInt(br.readLine());
            if (input == 0) {
                if (pq.isEmpty()) {
                    System.out.println(0);
                } else {
                    System.out.println(pq.poll());
                }
            } else if (input < 0) {
                pq.add(new Numbers(-input, false));
            } else if (input > 0) {
                pq.add(new Numbers(input, true));
            }
        }
    }

}



