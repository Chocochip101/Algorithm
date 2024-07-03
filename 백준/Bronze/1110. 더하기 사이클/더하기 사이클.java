import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int cycle = 1;
        int temp = nextNumber(N);
        while (temp != N) {
            temp = nextNumber(temp);
            cycle++;
        }
        System.out.println(cycle);
    }

    static int nextNumber(int n) {
        if (n < 10) {
            return n * 10 + n;
        }

        int sum = n % 10 + n / 10;

        return (n % 10) * 10 + sum % 10;
    }
}
