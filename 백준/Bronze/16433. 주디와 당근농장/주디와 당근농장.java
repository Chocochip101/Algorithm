import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {


    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Integer> NRC = Arrays.stream(br.readLine().split(" "))
                .map(Integer::parseInt)
                .collect(Collectors.toList());

        StringBuilder sb = new StringBuilder();

        if (((NRC.get(1) - 1) % 2 == 0 && (NRC.get(2) - 1) % 2 == 0) ||
                ((NRC.get(1) - 1) % 2 == 1 && (NRC.get(2) - 1) % 2 == 1)) {

            for (int i = 0; i < NRC.get(0); i++) {
                for (int j = 0; j < NRC.get(0); j++) {
                    if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                        sb.append("v");
                    } else {
                        sb.append(".");
                    }
                }
                sb.append("\n");
            }
        } else if (((NRC.get(1) - 1) % 2 == 0 && (NRC.get(2) - 1) % 2 == 1) ||
                ((NRC.get(1) - 1) % 2 == 1 && (NRC.get(2) - 1) % 2 == 0)) {
            for (int i = 0; i < NRC.get(0); i++) {
                for (int j = 0; j < NRC.get(0); j++) {
                    if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                        sb.append(".");
                    } else {
                        sb.append("v");
                    }
                }
                sb.append("\n");
            }
        }
        System.out.println(sb);
    }
}
