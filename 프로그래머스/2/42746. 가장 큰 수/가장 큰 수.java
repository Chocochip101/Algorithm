import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        ArrayList<String> list = new ArrayList<>();
        for(int i = 0; i < numbers.length; i++){
            list.add(String.valueOf(numbers[i]));
        }
        
        list.sort((o1, o2) -> {
           Integer a = Integer.parseInt(o1 + o2);
           Integer b = Integer.parseInt(o2 + o1);
            return Integer.compare(a, b);
        });
        String answer = "";
        for(int i = list.size() - 1; i > -1; i--){
            answer += list.get(i);
        }
        
        if(answer.startsWith("0")){
            return "0";
        }
        return answer;
    }
}