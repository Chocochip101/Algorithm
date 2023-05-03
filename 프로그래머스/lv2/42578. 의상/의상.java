import java.util.*;
import java.util.Map.*;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String, ArrayList<String>> map = new HashMap<>();
        for(String[] clothe: clothes){
            if(!map.containsKey(clothe[1])){
                ArrayList<String> arr = new ArrayList<>();
                arr.add(clothe[0]);
                map.put(clothe[1], arr);
            }else{
                ArrayList<String> arr = map.get(clothe[1]);
                arr.add(clothe[0]);
                map.put(clothe[1], arr);
            }
        }
        int answer = 0;
        if(map.size() == 1){
            answer = 0;
            for(Entry<String, ArrayList<String>> entry: map.entrySet()){
                answer += entry.getValue().size();
            }
            answer++;
        }
        else{
            answer = 1;
            for(Entry<String, ArrayList<String>> entry: map.entrySet()){
                answer *= (entry.getValue().size() + 1);
            }
        }
        return answer - 1;
    }
}