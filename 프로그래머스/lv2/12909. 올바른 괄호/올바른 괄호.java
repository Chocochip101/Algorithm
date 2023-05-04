import java.util.*;

class Solution {
    boolean solution(String s) {
        Stack<Character> stack = new Stack<>();
        for(int i = 0; i < s.length(); ++i){
            char now = s.charAt(i);
            if(now == '(')
                stack.push(now);
            else{
                if(stack.isEmpty())
                    return false;
                char top = stack.pop();
                if(top != '(')
                    return false;
            }
                
        }
        if(!stack.isEmpty())
            return false;
        return true;
    }
}