import java.util.*;

class Solution
{
    public int solution(String s)
    {
        Stack<Character> stk = new Stack<>();
        for(int i = 0; i< s.length(); i++){
            if(stk.isEmpty()){
                stk.push(s.charAt(i));
            }else{
                if(stk.peek() == s.charAt(i)){
                    stk.pop();
                }else{
                    stk.push(s.charAt(i));
                }
            }
        }
        
        while(!stk.isEmpty()){
            char c1 = stk.pop();
            if(stk.isEmpty() || c1 != stk.peek()){
                stk.push(c1);
                break;
            }
            stk.pop();
        }
        
        if(stk.isEmpty()){
            return 1;
        }
        return 0;
    }
}