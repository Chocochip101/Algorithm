import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.stream.IntStream;

public class Main {
    static Set<Integer> numbers = new HashSet<>();
    static int [] target = {1, 5, 10, 50};
    static int [] result;
    static int N;

    public static void main(String[] args) throws Exception {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bufferedReader.readLine());
        result = new int[N];
        combination(0, 0);
        System.out.println(numbers.size());
    }
    static void combination(int cnt, int idx) {
        if (cnt == N) {
            numbers.add(IntStream.of(result).sum());
            return;
        }
        for (int i = idx; i < 4; i++) {
            result[cnt] = target[i];
            combination(cnt + 1, i);
        }
    }
}

