import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> answer = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        int[] d = new int[102];
        int days = 1;
        for(int i = progresses.length - 1; i >=0; --i)
            stack.push(i);
        while(!stack.isEmpty()){
            int idx = stack.pop();
            if(progresses[idx] + speeds[idx] * days >= 100){
                d[days]++;
                continue;
            }else{
                stack.push(idx);
                days++;
            }
        }
        for(int i = 0; i < 102; ++i)
            if(d[i] != 0)
                answer.add(d[i]);
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}