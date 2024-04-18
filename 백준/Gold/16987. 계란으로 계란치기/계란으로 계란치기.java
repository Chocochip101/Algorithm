import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    static class Egg {
        public Egg(final int strength, final int wieght) {
            this.strength = strength;
            this.wieght = wieght;
        }

        int strength;
        int wieght;

    }

    static int N;
    static int result = 0;
    static List<Egg> eggs = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        for (int i = 0; i < N; i++) {
            List<Integer> integers = Arrays.stream(bf.readLine().split(" ")).map(Integer::parseInt)
                    .collect(Collectors.toList());
            eggs.add(new Egg(integers.get(0), integers.get(1)));
        }
        solve(0);
        System.out.println(result);
    }

    static int calculateBroken() {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (eggs.get(i).strength <= 0) {
                cnt++;
            }
        }
        return cnt;
    }

    public static void solve(int idx) {

        result = Math.max(result, calculateBroken());
        if (idx == N) {
            return ;
        }

        if(eggs.get(idx).strength <= 0){
            solve(idx + 1);
            return;
        }

        for (int i = 0; i < N; i++) {
            if (i == idx || eggs.get(i).strength <= 0 || eggs.get(idx).strength <= 0) {
                continue;
            }
            eggs.get(idx).strength -= eggs.get(i).wieght;
            eggs.get(i).strength -= eggs.get(idx).wieght;

            solve(idx + 1);

            eggs.get(idx).strength += eggs.get(i).wieght;
            eggs.get(i).strength += eggs.get(idx).wieght;
        }
    }
}

