import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        Stack<Integer>[] stk = new Stack[board.length];
        for(int i = 0; i < board.length; i++){
            stk[i] = new Stack<>();
        }
        
        for(int j = 0; j < board[0].length; j++){
            for(int i = board.length - 1; i > -1; i--){
                if(board[i][j] == 0){
                    break;
                }
                stk[j].push(board[i][j]);
            }
        }
        
        Stack<Integer> res = new Stack<>();
        int answer = 0;
        for(int move: moves){
            if(stk[move - 1].isEmpty()){
                continue;
            }
            int target = stk[move - 1].pop();
            if(!res.isEmpty() && res.peek() == target){
                res.pop();
                answer += 2;
            }else{
                res.push(target);
            }
        }
        
        
        return answer;
    }
}