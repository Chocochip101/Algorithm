import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(isCorrect(s.substring(i, len) + s.substring(0, i))){
                answer++;
            }
        }
        return answer;
    }
    public boolean isCorrect(String s){
        Stack<Character> stk = new Stack<>();
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '[' || s.charAt(i) == '(' || s.charAt(i) == '{'){
                stk.push(s.charAt(i));
            }else{
                if(stk.isEmpty()){
                    return false;
                }
                
                if(s.charAt(i) == ']' && stk.peek() != '['){
                    return false;
                }
                
                if(s.charAt(i) == '}' && stk.peek() != '{'){
                    return false;
                }
                
                if(s.charAt(i) == ')' && stk.peek() != '('){
                    return false;
                }
                
                stk.pop();
            }
        }
        
        if(!stk.isEmpty()){
            return false;
        }
        return true;
    }
}