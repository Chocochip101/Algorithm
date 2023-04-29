import java.util.*;

class Solution {
    public String solution(String s) {
        String[] chars = s.split(" ");
        int[] numbers = new int[chars.length];
        for(int i = 0; i < chars.length; ++i){
            numbers[i] = Integer.parseInt(chars[i]);
        }
        String answer = Integer.toString(Arrays.stream(numbers).min().getAsInt()) + " " + Integer.toString(Arrays.stream(numbers).max().getAsInt());
        return answer;
    }
}