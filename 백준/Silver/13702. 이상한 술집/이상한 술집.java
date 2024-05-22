import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static int N;
    static long K;
    static long maxLimit = -1;

    static int[] numbers;

    public static void main(String... args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> NAndK = Arrays.stream(bufferedReader.readLine().split(" ")).map(Integer::parseInt)
                .collect(Collectors.toList());
        N = NAndK.get(0);
        K = NAndK.get(1);

        numbers = new int[N];
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(bufferedReader.readLine());
            maxLimit = Math.max(maxLimit, numbers[i]);
        }
        System.out.println(binarySearch());
    }

    static long binarySearch() {
        long left = 0;
        long right = maxLimit + 2;
        long res = 0;
        while (left < right) {
            long mid = (left + right) / 2;
            if (canDivide(mid)) {
                res = Math.max(res, mid);
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return res;
    }

    static boolean canDivide(long mid) {
        if(mid == 0){
            return true;
        }
        int res = 0;
        for (int i = 0; i < N; i++) {
            res += numbers[i] / mid;
        }
        return K <= res;
    }
}


