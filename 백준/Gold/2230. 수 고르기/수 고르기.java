import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        String[] split = bufferedReader.readLine().split(" ");
        int N = Integer.parseInt(split[0]);
        int M = Integer.parseInt(split[1]);

        int[] numbers = new int[N];
        for (int i = 0; i < N; ++i) {
            numbers[i] = Integer.parseInt(bufferedReader.readLine());
        }

        Arrays.sort(numbers);

        int left = 0;
        int right = 1;

        int answer = Integer.MAX_VALUE;
        while (left < N) {
            if (numbers[right] - numbers[left] == M) {
                answer = M;
                break;
            } else if (numbers[right] - numbers[left] > M) {
                answer = Math.min(answer, numbers[right] - numbers[left]);
                left++;
            }else {
                if (right == N - 1) {
                    left++;
                } else {
                    right++;
                }
            }
        }
        System.out.println(answer);
    }
}
