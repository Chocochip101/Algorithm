import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static long N;

    static class Stage {
        long t;
        long a;
        long h;

        Stage(long t, long a, long h) {
            this.t = t;
            this.a = a;
            this.h = h;
        }

        boolean isFinish() {
            return h <= 0;
        }

        @Override
        public String toString() {
            return "Stage{" +
                    "t=" + t +
                    ", a=" + a +
                    ", h=" + h +
                    '}';
        }
    }

    public static void main(String... args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<Long> NHatk = Arrays.stream(br.readLine().split(" "))
                .map(Long::parseLong)
                .collect(Collectors.toList());
        N = NHatk.get(0);
        long Hatk = NHatk.get(1);

        List<Stage> stages = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            List<Long> tah = Arrays.stream(br.readLine().split(" "))
                    .map(Long::parseLong)
                    .collect(Collectors.toList());
            stages.add(new Stage(tah.get(0), tah.get(1), tah.get(2)));
        }

        long left = 0;
        long right = Long.MAX_VALUE - 1;

        while (left <= right) {
            long mid = (left + right) / 2;

            if (canClearStages(Hatk, mid, stages)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(left);
    }

    static boolean canClearStages(long Hatk, long Hmaxhp, List<Stage> stages) {
        long Hcurhp = Hmaxhp;
        for (Stage stage : stages) {
            if (stage.t == 2) {
                Hatk += stage.a;
                Hcurhp += stage.h;
                if (Hcurhp >= Hmaxhp) {
                    Hcurhp = Hmaxhp;
                }
                continue;
            }
            Hcurhp = clear(Hatk, Hcurhp, stage);
            if(Hcurhp <= 0){
                return false;
            }
        }
        return true;
    }

    static long clear(long Hatk, long Hcurhp, Stage stage) {
        long res = stage.h / Hatk;

        if (stage.h % Hatk == 0) {
            Hcurhp -= stage.a * (res - 1);
        } else {
            Hcurhp -= stage.a * res;
        }

        return Hcurhp;
    }
}
