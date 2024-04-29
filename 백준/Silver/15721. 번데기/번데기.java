import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static int MAX = 10010;
    static List<Boolean> ppundegi = new ArrayList<>();

    public static void main(String... args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        init();
        int A = Integer.parseInt(bf.readLine());
        int T = Integer.parseInt(bf.readLine());
        int target = Integer.parseInt(bf.readLine());

        int people = 0;
        int targetCnt = 0;

        if (target == 0) {
            while (targetCnt < T) {
                if(ppundegi.get(people)){
                    targetCnt++;
                }
                people++;
            }
        } else {
            while (targetCnt < T) {
                if(!ppundegi.get(people)){
                    targetCnt++;
                }
                people++;
            }
        }
        people--;
        System.out.println(people % A);
    }

    static void init() {
        int level = 2;
        while (ppundegi.size() < MAX) {
            ppundegi.add(true);
            ppundegi.add(false);
            ppundegi.add(true);
            ppundegi.add(false);

            for (int i = 0; i < level; i++) {
                ppundegi.add(true);
            }
            for (int i = 0; i < level; i++) {
                ppundegi.add(false);
            }
            level++;
        }
    }
}


