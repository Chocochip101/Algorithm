import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {


    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < T; tc++) {
            String s = br.readLine();
            String even = "";
            for (int i = 0; i < s.length(); i += 2) {
                even += s.charAt(i);
            }

            String odd = "";
            for (int i = 1; i < s.length(); i += 2) {
                odd += s.charAt(i);
            }
            if (s.length() % 2 == 0) {
                System.out.println(even);
                System.out.println(odd);
            } else {
                System.out.println(even + odd);
                System.out.println(odd + even);
            }
        }
    }
}
