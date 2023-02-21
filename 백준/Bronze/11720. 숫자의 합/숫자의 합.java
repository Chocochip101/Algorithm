import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Integer N = sc.nextInt();
        String S = sc.next();
        
        char[] cNum = S.toCharArray();
        Integer ans = 0;
        for(int i = 0 ; i < cNum.length; ++ i){
            ans += cNum[i] - '0';
        }
        System.out.println(ans);
    }
}
