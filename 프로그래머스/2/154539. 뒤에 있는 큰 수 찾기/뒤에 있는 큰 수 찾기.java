import java.util.*;

class Solution {
    private int N;
    public int[] solution(int[] numbers) {
        N = numbers.length;
        int[] answer = new int[N];
        Arrays.fill(answer, -1);
        Stack<Integer> stack = new Stack<>();
        
        stack.push(0);
        for(int i = 1; i < numbers.length; i++){
            while(!stack.isEmpty() && numbers[stack.peek()] < numbers[i]){
                answer[stack.pop()] = numbers[i];
            }
            stack.push(i);
        }
        return answer;
    }
}