import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        ArrayList<Integer> _li = new ArrayList<Integer>();
        for(int i = 0; i < N; ++i){
            int a = sc.nextInt();
            _li.add(a);
        }
        Collections.sort(_li);

        for(Integer num: _li){
            System.out.println(num);
        }
    }
}
