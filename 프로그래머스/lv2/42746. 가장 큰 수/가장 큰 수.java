import java.util.*;

class Solution {

    public String solution(int[] numbers) {
        String[] s_num = new String[numbers.length];
        for(int i = 0; i < numbers.length; ++i){
            s_num[i] = Integer.toString(numbers[i]);
        }
        Arrays.sort(s_num, (a, b)->(b+a).compareTo(a+b));
        
        String answer = "";
        for(String a: s_num){
            answer += a;
        }
        if(answer.charAt(0) == '0'){
            return "0";
        }
        return answer;
    }
}