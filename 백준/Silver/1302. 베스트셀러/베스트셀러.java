import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

public class Main {

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        Map<String, Integer> names = new HashMap<>();

        while (N-- > 0) {
            String name = br.readLine();
            if (names.containsKey(name)) {
                names.put(name, names.get(name) + 1);
            } else {
                names.put(name, 1);
            }
        }

        int cnt = 0;

        List<String> keys = names.keySet().stream()
                .sorted()
                .collect(Collectors.toList());
        String result = "";
        for (String name : keys) {
            if (names.get(name) > cnt) {
                cnt = names.get(name);
                result = name;
            }
        }
        System.out.println(result);
    }

}
