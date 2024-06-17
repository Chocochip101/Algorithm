import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {

    static Set<String> sets = new HashSet<>();

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();

        for(int i = 0; i < s.length(); i++){
            for(int j = i + 1; j <= s.length(); j++){
                sets.add(s.substring(i, j));
            }
        }
        System.out.println(sets.size());
    }
}



