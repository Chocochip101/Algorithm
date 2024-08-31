import java.util.*;

class Solution {
    boolean solution(String s) {

        Stack<Character> stk = new Stack<>();
        for(int i = 0; i< s.length(); i++){
            if(s.charAt(i) == '('){
                stk.add('(');
            }else{
                if(stk.isEmpty() || stk.peek() == ')'){
                    return false;
                }
                stk.pop();
            }
        }
        if(stk.size() != 0){
            return false;
        }
        return true;
    }
}