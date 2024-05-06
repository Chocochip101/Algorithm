import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static List<List<Integer>> switchs = new ArrayList<>();
    static List<Integer> NandM;

    public static void main(String... args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        NandM = Arrays.stream(bf.readLine().split(" ")).map(Integer::parseInt)
                .collect(Collectors.toList());

        for (int i = 0; i < NandM.get(0); i++) {
            switchs.add(Arrays.stream(bf.readLine().split(" ")).map(Integer::parseInt)
                    .collect(Collectors.toList()));
        }

        for (int i = 0; i < NandM.get(0); i++) {
            if(canLight(i)){
                System.out.println(1);
                return;
            }
        }
        System.out.println(0);
    }

    static boolean canLight(int removeIdx) {
        boolean[] lamps = new boolean[NandM.get(1)];
        for (int i = 0; i < NandM.get(0); i++) {
            if (i == removeIdx) {
                continue;
            }

            for (int j = 1; j <= switchs.get(i).get(0); j++) {
                if (!lamps[switchs.get(i).get(j) - 1]) {
                    lamps[switchs.get(i).get(j) - 1] = true;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < NandM.get(1); i++) {
            if(lamps[i]){
                cnt++;
            }
        }
        if(cnt == NandM.get(1)){
            return true;
        }
        return false;
    }
}


