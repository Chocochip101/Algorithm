import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        int[] first = {1, 2, 3, 4, 5};
        int[] second = {2, 1, 2, 3, 2, 4, 2, 5};
        int[] third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int firstCnt = 0;
        int secondCnt = 0;
        int thirdCnt = 0;
        for(int i = 0; i < answers.length; i++){
            if(answers[i] == first[i % 5]){
                firstCnt++;
            }
            if(answers[i] == second[i % 8]){
                secondCnt++;
            }
            if(answers[i] == third[i % 10]){
                thirdCnt++;
            }
        }
        
        int maxCnt = Math.max(firstCnt, secondCnt);
        maxCnt = Math.max(maxCnt, thirdCnt);
        System.out.println(firstCnt);
        System.out.println(secondCnt);
        System.out.println(thirdCnt);
        List<Integer> answer = new ArrayList<>();
        if(maxCnt == firstCnt){
            answer.add(1);
        }
        if(maxCnt == secondCnt){
            answer.add(2);
        }
        if(maxCnt == thirdCnt){
            answer.add(3);
        }
        
        int[] ans = new int[answer.size()];
        for(int i = 0; i< answer.size(); i++){
            ans[i] = answer.get(i);
        }
        return ans;
    }
}