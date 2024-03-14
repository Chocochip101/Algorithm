
import java.util.*;

class Main {
    public static String[] answers;
    public static int cnt;
    public static void main(String[] args) {
        solution();
    }

    public static void solution(){
        Scanner scanner = new Scanner(System.in);
        answers = scanner.nextLine().split(" ");
        cnt = 0;
        solve(0, 0, 0, 0);
        System.out.println(cnt);
    }
    
    public static void solve(int nowIndex, int prevNumber, int redundantCnt, int answerCnt){
        if(redundantCnt >= 2){
            return;
        }
        if (nowIndex >= answers.length) {
            if(answerCnt >= 5){
                cnt += 1;
            }
            return;
        }

        for(int i = 1; i < 6; ++i){
            // 이전이랑 겹칠 경우 redundantCnt + 1
            if(i == prevNumber){
                if(i == Integer.parseInt(answers[nowIndex])){
                    solve(nowIndex + 1, i, redundantCnt + 1, answerCnt + 1);
                }else{
                    solve(nowIndex + 1, i, redundantCnt + 1, answerCnt);
                }
            }else{
                if(i == Integer.parseInt(answers[nowIndex])){
                    solve(nowIndex + 1, i, 0, answerCnt + 1);

                }else{
                    solve(nowIndex + 1, i,  0, answerCnt);
                }
            }
        }
    }
}

    