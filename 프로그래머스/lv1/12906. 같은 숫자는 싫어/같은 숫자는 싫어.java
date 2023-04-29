import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        ArrayList<Integer> answer = new ArrayList<>();
        int prev = -1;
        for(int i = 0; i < arr.length; ++i){
            if(prev == -1){
                prev = arr[i];
                answer.add(arr[i]);
            }else{
                if(prev == arr[i])
                    continue;
                else{
                    prev = arr[i];
                    answer.add(arr[i]);
                }
            }
        }


        return answer.stream()
	.mapToInt(Integer::intValue)
    	.toArray();
    }
}