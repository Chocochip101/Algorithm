import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int N;
    static int[] numbers = new int[1010];

    public static void main(String... args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(bf.readLine());
        }

        int answer = 0;
        for (int i = 0; i < N; i++) {
            answer = Math.max(answer, solve(numbers[i]));
        }
        System.out.println(answer);
    }

    static int solve(int target) {
        int cnt = 1;
        int result = 1;
        int prev = numbers[0];

        for (int i = 1; i < N; i++) {
            if (target == numbers[i]) {
                continue;
            }

            if (prev != numbers[i]) {
                cnt = 1;
            } else {
                cnt++;
                result = Math.max(result, cnt);
            }
            prev = numbers[i];
        }
        return result;
    }

}


