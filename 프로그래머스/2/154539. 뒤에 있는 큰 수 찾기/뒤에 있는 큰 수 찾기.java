import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        Arrays.fill(answer, -1);
        int lastMax = numbers[numbers.length - 1];
        
        for(int i = numbers.length - 2; i > -1; --i){
            if(numbers[i] >= lastMax){
                lastMax = Math.max(numbers[i], lastMax);
                continue;
            }
            for(int j = i + 1; j <numbers.length; j++){
                if(numbers[i] < numbers[j]){
                    answer[i] = numbers[j];
                    break;
                }
                if(numbers[i] >= numbers[j] && numbers[i] < answer[j]){
                    answer[i] = answer[j];
                    break;
                }
            }
            lastMax = Math.max(numbers[i], lastMax);
        }
        return answer;
    }
    
}