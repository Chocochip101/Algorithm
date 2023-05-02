import java.util.*;
import java.util.Map.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> map = new HashMap<>();
        for(String part: participant){
            if(!map.containsKey(part))
                map.put(part, 1);
            else
                map.put(part, map.get(part) + 1);
        }
        for(String comp: completion){
            map.put(comp, map.get(comp) - 1);
        }
        for(Entry<String, Integer> entry: map.entrySet()){
            if(entry.getValue() == 1)
                return entry.getKey();
        }
        return answer;
    }
}