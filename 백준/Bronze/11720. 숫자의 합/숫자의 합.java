import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String sNum = sc.next();
        char[] cNum = sNum.toCharArray();
        int ans = 0;
        for(int i = 0; i < N; ++i){
            ans += cNum[i] - '0';
        }
        System.out.println(ans);
    }
}
