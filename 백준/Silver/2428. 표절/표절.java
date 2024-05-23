import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static int N;
    static List<Integer> files;

    public static void main(String... args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bufferedReader.readLine());
        files = Arrays.stream(bufferedReader.readLine().split(" ")).map(Integer::parseInt).sorted()
                .collect(Collectors.toList());

        long res = 0;
        for (int i = 0; i < N; i++) {
            res += (binarySearch(((double) (files.get(i) * 10) / 9)) - i);
        }
        System.out.println(res);
        /*
        1 3 5 10 11 11 12 90 91 100 101 100000000
               2+ 2+ 1+   2+ 2+  1
         */

    }

    // target 이하 중 가장 오른쪽
    static long binarySearch(double target) {
        int left = 0;
        int right = N;

        int ret = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            if (files.get(mid) <= target) {
                ret = Math.max(ret, mid);
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return ret;
    }
}


