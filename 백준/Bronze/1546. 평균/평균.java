import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        ArrayList<Integer> scores = new ArrayList<>();

        int total = 0;
        for(int i = 0; i < N; ++ i){
            scores.add(sc.nextInt());
            total += scores.get(i);
        }
        
        System.out.println(total * 100.0 / Collections.max(scores) / N);
    }
}
