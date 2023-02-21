import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        List<Double> A = new ArrayList<>();

        for(int i = 0; i < N; ++i){
            A.add(sc.nextDouble());
        }
        double m = Collections.max(A);

        double res = 0;
        for(int i = 0; i < N; ++i){
            res += (A.get(i)/m * 100);
        }
        System.out.print(res / N);
    }
}
