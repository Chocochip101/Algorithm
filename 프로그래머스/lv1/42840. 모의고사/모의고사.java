import java.util.*;
class Solution {
    public int returnCnt(int[] person, int[] answer){
        int cnt = 0;
        for(int i = 0; i < answer.length; ++i){
            if(answer[i] == person[i % person.length])
                cnt++;
        }
        return cnt;
    }
    public int[] solution(int[] answers) {
        ArrayList<Integer> answer = new ArrayList<>();
        int[][] person = {{1, 2, 3, 4, 5},
                             {2, 1, 2, 3, 2, 4, 2, 5}
                                ,{3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
        int cnt = -1;
        for(int i = 0; i < 3; ++i){
            int res = returnCnt(person[i], answers);
            if(res > cnt){
                cnt = res;
                answer.clear();
                answer.add(i + 1);
            }else if(res == cnt){
                answer.add(i + 1);
            }else
                continue;
        }
        
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}