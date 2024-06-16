import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {


    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            String input = br.readLine();
            if (input.equals("0")) {
                break;
            }

            solve(input);
        }
    }

    static void solve(String s) {
        for (int i = 0; i < s.length() / 2; i++) {
            if(s.charAt(i) != s.charAt(s.length() - i - 1)){
                System.out.println("no");
                return;
            }
        }
        System.out.println("yes");
    }

}



